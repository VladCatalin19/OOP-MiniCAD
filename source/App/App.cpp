#include "App.h"

#include "../Shapes/Shape.h"
#include "../Utils/Constants.h"
#include "../ShapeFactory/ShapeFactory.h"

#include "../ShapeVisitors/DrawVisitor.h"
#include "../ShapeVisitors/PrintVisitor.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

App::App()
{
	drawVisitor = nullptr;
}

App::~App()
{
	ClearShapesArray();
	ClearDrawVisitor();
}

void App::ReadFromFile(std::string const& fileName)
{
	ClearShapesArray();
	ClearDrawVisitor();

	std::ifstream inputStream;
	OpenFileAndGetStream(fileName, inputStream);
	ReadShapes(inputStream, ReadNumberOfShapes(inputStream));

	drawVisitor = new DrawVisitor();
}

void App::Run()
{
	for (Shape* s : shapes)
	{
		s->Accept(*drawVisitor);
	}
}

void App::WriteToFile(std::string const& fileName)
{
	drawVisitor->WriteImage(fileName);
}

void App::ClearShapesArray()
{
	for (Shape* s : shapes)
	{
		delete s;
	}
	shapes.clear();
}

void App::ClearDrawVisitor()
{
	delete drawVisitor;
	drawVisitor = nullptr;
}

void App::OpenFileAndGetStream(std::string fileName, std::ifstream& inputStream)
{
	inputStream = std::ifstream(fileName);
	if (!inputStream)
	{
		throw std::invalid_argument(ErrorMessages::CouldNotOpenFile + " " + fileName);
	}
}

int App::ReadNumberOfShapes(std::ifstream& inputStream)
{
	std::string tmp;
	std::getline(inputStream, tmp);
	int shapesNum = 0;
	try
	{
		shapesNum = std::stoi(tmp);
	}
	catch (...)
	{
		throw std::runtime_error(ErrorMessages::CouldNotReadShapesNum);
	}
	return shapesNum;
}

void App::ReadShapes(std::ifstream& inputStream, int shapesNum)
{
	shapes = std::vector<Shape*>();
	shapes.reserve(shapesNum);

	for (int i = 0; i < shapesNum; ++i)
	{
		ReadShapeAndAddItToShapeArray(inputStream);
	}
}

void App::ReadShapeAndAddItToShapeArray(std::ifstream& inputStream)
{
	ShapeFactory& shapeFactory = ShapeFactory::GetInstance();
	std::string tmp;
	std::getline(inputStream, tmp);
	Shape* shape = shapeFactory.CreateShape(tmp);

	if (shape == nullptr)
	{
		throw std::invalid_argument(ErrorMessages::InvalidShape + " " + tmp + " ");
	}
	else
	{
		shapes.push_back(shape);
	}
}
