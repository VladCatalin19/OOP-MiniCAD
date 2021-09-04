#include "App.hpp"

#include <Shapes/Shape.hpp>
#include <Utils/Constants.hpp>
#include <ShapeFactory/ShapeFactory.hpp>
#include <ShapeVisitors/DrawVisitor.hpp>
#include <ShapeVisitors/PrintVisitor.hpp>

#include <fstream>				// std::ifstream
#include <memory>               // std::make_unique, std::unique_ptr, std::move
#include <stdexcept>            // std::invalid_argument, std::out_of_range
#include <string>				// std::string
#include <vector>				// std::vector

namespace MiniCAD
{
    App::App()
    {
        draw_visitor = nullptr;
    }

    App::~App()
    {
        ClearShapesArray();
        ClearDrawVisitor();
    }

    void App::ReadFromFile(const std::string &filen_name)
    {
        ClearShapesArray();
        ClearDrawVisitor();

        std::ifstream input_stream;
        OpenFileAndGetStream(filen_name, input_stream);
        ReadShapes(input_stream, ReadNumberOfShapes(input_stream));

        draw_visitor = std::make_unique<DrawVisitor>();
    }

    void App::Run()
    {
        for (const auto &shape : shapes)
        {
            shape->Accept(*draw_visitor);
        }
    }

    void App::WriteToFile(const std::string &fileName)
    {
        draw_visitor->WriteImage(fileName);
    }

    void App::ClearShapesArray()
    {
        shapes.clear();
    }

    void App::ClearDrawVisitor()
    {
        draw_visitor = nullptr;
    }

    void App::OpenFileAndGetStream(std::string file_name, std::ifstream &input_stream)
    {
        input_stream = std::ifstream(file_name);
        if (input_stream.fail())
        {
            throw std::invalid_argument(std::string(ErrorMessages::CouldNotOpenFile) + " " + file_name);
        }
    }

    int App::ReadNumberOfShapes(std::ifstream &inputStream)
    {
        std::string tmp;
        std::getline(inputStream, tmp);
        int shapes_num = 0;
        try
        {
            shapes_num = std::stoi(tmp);
        }
        catch (const std::invalid_argument &)
        {
            throw std::runtime_error(ErrorMessages::CouldNotReadShapesNum);
        }
        catch (const std::out_of_range &)
        {
            throw std::runtime_error(ErrorMessages::CouldNotReadShapesNum);
        }
        return shapes_num;
    }

    void App::ReadShapes(std::ifstream &input_stream, int shapes_num)
    {
        shapes.clear();
        shapes.reserve(static_cast<std::size_t>(shapes_num));

        for (int i = 0; i < shapes_num; ++i)
        {
            ReadShapeAndAddItToShapeArray(input_stream);
        }
    }

    void App::ReadShapeAndAddItToShapeArray(std::ifstream& input_stream)
    {
        ShapeFactory &shape_factory = ShapeFactory::GetInstance();
        std::string line;
        std::getline(input_stream, line);
        std::unique_ptr<Shape> shape = shape_factory.CreateShape(line);

        if (shape == nullptr)
        {
            throw std::invalid_argument(std::string(ErrorMessages::InvalidShape) + " " + line + " ");
        }
        else
        {
            shapes.push_back(std::move(shape));
        }
    }
}
