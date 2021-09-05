#include "App.hpp"

#include <Shapes/Shape.hpp>
#include <Utils/Constants.hpp>
#include <ShapeFactory/ShapeFactory.hpp>
#include <ShapeVisitors/DrawVisitor.hpp>
#include <ShapeVisitors/PrintVisitor.hpp>

#include <fstream>				// std::ifstream
#include <memory>               // std::make_unique, std::unique_ptr, std::move
#include <stdexcept>            // std::invalid_argument, std::out_of_range
#include <string>				// std::string, std::getline
#include <vector>				// std::vector

static std::ifstream GetInputFileStream(const std::string &input_file_name)
{
    std::ifstream input_stream(input_file_name);
    if (input_stream.fail())
    {
        throw std::invalid_argument(std::string(MiniCAD::ErrorMessages::CouldNotOpenFile) + " " + input_file_name);
    }
    return input_stream;
}

static unsigned ReadNumberOfShapes(std::ifstream &input_stream)
{
    std::string tmp;
    std::getline(input_stream, tmp);
    unsigned shapes_number = 0;
    try
    {
        shapes_number = static_cast<unsigned>(std::stol(tmp));
    }
    catch (const std::invalid_argument &)
    {
        throw std::runtime_error(MiniCAD::ErrorMessages::CouldNotReadShapesNum);
    }
    catch (const std::out_of_range &)
    {
        throw std::runtime_error(MiniCAD::ErrorMessages::CouldNotReadShapesNum);
    }
    return shapes_number;
}

static std::vector<std::unique_ptr<MiniCAD::Shape>> ReadShapes(std::ifstream &input_stream)
{
    unsigned shapes_number = ReadNumberOfShapes(input_stream);

    std::vector<std::unique_ptr<MiniCAD::Shape>> shapes;
    shapes.reserve(shapes_number);

    MiniCAD::ShapeFactory &shape_factory = MiniCAD::ShapeFactory::GetInstance();
    std::string line;

    for (unsigned shape_index = 0U; shape_index < shapes_number; ++shape_index)
    {
        std::getline(input_stream, line);
        std::unique_ptr<MiniCAD::Shape> shape = shape_factory.CreateShape(line);

        if (shape == nullptr)
        {
            throw std::invalid_argument(std::string(MiniCAD::ErrorMessages::InvalidShape) + " " + line + " ");
        }
        else
        {
            shapes.push_back(std::move(shape));
        }
    }
    return shapes;
}

static std::unique_ptr<MiniCAD::DrawVisitor> DrawShapes(const std::vector<std::unique_ptr<MiniCAD::Shape>> &shapes)
{
    std::unique_ptr<MiniCAD::DrawVisitor> draw_visitor = std::make_unique<MiniCAD::DrawVisitor>();

    for (const auto &shape : shapes)
    {
        shape->Accept(*draw_visitor);
    }

    return draw_visitor;
}

static void WriteImageToFile(const std::unique_ptr<MiniCAD::DrawVisitor> &draw_visitor, const std::string &output_file_name)
{
    draw_visitor->WriteImage(output_file_name);
}

namespace MiniCAD
{
    void App::Run(const std::string &input_file_name, const std::string &output_file_name)
    {
        std::ifstream input_stream = GetInputFileStream(input_file_name);
        std::vector<std::unique_ptr<Shape>> shapes = ReadShapes(input_stream);
        std::unique_ptr<DrawVisitor> draw_visitor = DrawShapes(shapes);
        WriteImageToFile(draw_visitor, output_file_name);
    }
}
