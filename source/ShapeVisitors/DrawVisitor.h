#include "ShapeVisitor.h"
#include <opencv2/core.hpp>
#include <opencv2/core/matx.hpp>

class DrawVisitor : public ShapeVisitor
{
private:
	cv::Mat image;

public:
    DrawVisitor();
    virtual ~DrawVisitor();

	virtual void Visit(Canvas const& canvas) override;
	virtual void Visit(Line const& line) override;
	virtual void Visit(Square const& square) override;
	virtual void Visit(Rectangle const& rectangle) override;
	virtual void Visit(Circle const& circle) override;
	virtual void Visit(Triangle const& triangle) override;
	virtual void Visit(Diamond const& diamond) override;
	virtual void Visit(Polygon const& polygon) override;

	void WriteImage(std::string const& fileName);

private:
	struct Cell
	{
		int x, y;
		Cell(int x, int y) : x(x), y(y) {}
	};
	void FloodFill(
		int xStart, int yStart, cv::Vec4b const& outlineColor,
		cv::Vec4b const& fillColor
	);
};
