#pragma once

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

class Shape;
class DrawVisitor;

class App
{
private:
	std::vector<Shape*> shapes;
	DrawVisitor* drawVisitor;

public:
	App();
	~App();

	void ReadFromFile(std::string const& fileName);
	void Run();
	void WriteToFile(std::string const& fileName);

private:
	void ClearShapesArray();
	void ClearDrawVisitor();
	void OpenFileAndGetStream(std::string fileName, std::ifstream& inputStream);
	int ReadNumberOfShapes(std::ifstream& inputStream);
	void ReadShapes(std::ifstream& inputStream, int shapesNum);
	void ReadShapeAndAddItToShapeArray(std::ifstream& inputStream);
};
