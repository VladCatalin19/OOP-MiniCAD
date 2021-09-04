#ifndef MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED

#include <Shapes/Shape.hpp>

#include <memory>               // std::unique_ptr
#include <string>               // std::string

namespace MiniCAD
{
    class ShapeFactory
    {
    private:
        ShapeFactory() {}

    public:
        static ShapeFactory& GetInstance()
        {
            static ShapeFactory instance;
            return instance;
        }

        ShapeFactory(const ShapeFactory &) = delete;
        void operator=(const ShapeFactory &) = delete;

        std::unique_ptr<Shape> CreateShape(const std::string &line) const;
    };
}

#endif // MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED
