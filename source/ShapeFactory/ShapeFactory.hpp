#ifndef MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED

#include <string>

class Shape;

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

    ShapeFactory(ShapeFactory const&) = delete;
    void operator=(ShapeFactory const&) = delete;

    Shape* CreateShape(std::string const& line) const;
};

#endif // MINICAD_SOURCE_SHAPEFACTORY_SHAPEFACTORY_HPP_INCLUDED
