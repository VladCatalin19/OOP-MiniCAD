#ifndef MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED

#include <Shapes/Shape.hpp>

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

        Shape *CreateShape(const std::string &line) const;
    };
}

#endif // MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED
