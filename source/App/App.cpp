#include "App.hpp"

#include <Shapes/Shape.hpp>
#include <Utils/Constants.hpp>
#include <ShapeFactory/ShapeFactory.hpp>
#include <ShapeVisitors/DrawVisitor.hpp>
#include <ShapeVisitors/PrintVisitor.hpp>

#include <fstream>				// std::ifstream
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

        draw_visitor = new DrawVisitor();
    }

    void App::Run()
    {
        for (Shape *s : shapes)
        {
            s->Accept(*draw_visitor);
        }
    }

    void App::WriteToFile(const std::string &fileName)
    {
        draw_visitor->WriteImage(fileName);
    }

    void App::ClearShapesArray()
    {
        for (Shape *s : shapes)
        {
            delete s;
        }
        shapes.clear();
    }

    void App::ClearDrawVisitor()
    {
        delete draw_visitor;
        draw_visitor = nullptr;
    }

    void App::OpenFileAndGetStream(std::string file_name, std::ifstream &input_stream)
    {
        input_stream = std::ifstream(file_name);
        if (!input_stream)
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
        catch (...)
        {
            throw std::runtime_error(ErrorMessages::CouldNotReadShapesNum);
        }
        return shapes_num;
    }

    void App::ReadShapes(std::ifstream &input_stream, int shapes_num)
    {
        shapes = std::vector<Shape*>();
        shapes.reserve(shapes_num);

        for (int i = 0; i < shapes_num; ++i)
        {
            ReadShapeAndAddItToShapeArray(input_stream);
        }
    }

    void App::ReadShapeAndAddItToShapeArray(std::ifstream& input_stream)
    {
        ShapeFactory &shape_factory = ShapeFactory::GetInstance();
        std::string tmp;
        std::getline(input_stream, tmp);
        Shape *shape = shape_factory.CreateShape(tmp);

        if (shape == nullptr)
        {
            throw std::invalid_argument(std::string(ErrorMessages::InvalidShape) + " " + tmp + " ");
        }
        else
        {
            shapes.push_back(shape);
        }
    }
}
