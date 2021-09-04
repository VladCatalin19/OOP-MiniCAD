#ifndef MINICAD_SOURCE_APP_APP_HPP_INCLUDED
#define MINICAD_SOURCE_APP_APP_HPP_INCLUDED

#include <Shapes/Shape.hpp>
#include <ShapeVisitors/DrawVisitor.hpp>

#include <fstream>				// std::ifstream
#include <memory>               // std::unique_ptr
#include <string>				// std::string
#include <vector>				// std::vector

namespace MiniCAD
{
    class App
    {
    private:
        std::vector<std::unique_ptr<Shape>> shapes;
        std::unique_ptr<DrawVisitor> draw_visitor;

    public:
        App();
        ~App();

        void ReadFromFile(const std::string &file_name);
        void Run();
        void WriteToFile(const std::string &file_name);

    private:
        void ClearShapesArray();
        void ClearDrawVisitor();
        void OpenFileAndGetStream(std::string file_name, std::ifstream &input_stream);
        int ReadNumberOfShapes(std::ifstream &input_stream);
        void ReadShapes(std::ifstream &input_stream, int shapes_num);
        void ReadShapeAndAddItToShapeArray(std::ifstream &input_stream);
    };
}

#endif // MINICAD_SOURCE_APP_APP_HPP_INCLUDED
