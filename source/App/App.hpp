#ifndef MINICAD_SOURCE_APP_APP_HPP_INCLUDED
#define MINICAD_SOURCE_APP_APP_HPP_INCLUDED

#include <Shapes/Shape.hpp>
#include <ShapeVisitors/DrawVisitor.hpp>

#include <fstream>				// std::ifstream
#include <string>				// std::string
#include <vector>				// std::vector

class App
{
private:
	std::vector<Shape*> shapes;
	DrawVisitor *drawVisitor;

public:
	App();
	~App();

	void ReadFromFile(const std::string &fileName);
	void Run();
	void WriteToFile(const std::string &fileName);

private:
	void ClearShapesArray();
	void ClearDrawVisitor();
	void OpenFileAndGetStream(std::string fileName, std::ifstream &inputStream);
	int ReadNumberOfShapes(std::ifstream &inputStream);
	void ReadShapes(std::ifstream &inputStream, int shapesNum);
	void ReadShapeAndAddItToShapeArray(std::ifstream &inputStream);
};

#endif // MINICAD_SOURCE_APP_APP_HPP_INCLUDED
