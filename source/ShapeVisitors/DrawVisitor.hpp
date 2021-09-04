#ifndef MINICAD_SOURCE_SHAPEVISITORS_DRAWVISITOR_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPEVISITORS_DRAWVISITOR_HPP_INCLUDED

#include "ShapeVisitor.hpp"

#include <Shapes/Canvas.hpp>
#include <Shapes/Line.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Diamond.hpp>
#include <Shapes/Polygon.hpp>

#include <opencv2/core/matx.hpp>    // cv::Vec4b
#include <opencv2/core/mat.hpp>     // cv::Mat

#include <string>                   // std::string

namespace MiniCAD
{
    class DrawVisitor : public ShapeVisitor
    {
    private:
        cv::Mat image;

    public:
        DrawVisitor();
        virtual ~DrawVisitor();

        virtual void Visit(const Canvas &canvas) override;
        virtual void Visit(const Line &line) override;
        virtual void Visit(const Square &square) override;
        virtual void Visit(const Rectangle &rectangle) override;
        virtual void Visit(const Circle &circle) override;
        virtual void Visit(const Triangle &triangle) override;
        virtual void Visit(const Diamond &diamond) override;
        virtual void Visit(const Polygon &polygon) override;

        void WriteImage(const std::string &fileName);

    private:
        void FloodFill(int x_start, int y_start, const cv::Vec4b &outline_color,
                       const cv::Vec4b &fill_color);

        struct Cell
        {
            int x, y;
            Cell(int x, int y) : x(x), y(y) {}
        };
    };
}

#endif // MINICAD_SOURCE_SHAPEVISITORS_DRAWVISITOR_HPP_INCLUDED
