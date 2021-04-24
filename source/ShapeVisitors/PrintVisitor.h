#include "ShapeVisitor.h"

class PrintVisitor : public ShapeVisitor
{
public:
    PrintVisitor();
    ~PrintVisitor();

	virtual void Visit(Canvas const& canvas) override;
	virtual void Visit(Line const& line) override;
	virtual void Visit(Square const& square) override;
	virtual void Visit(Rectangle const& rectangle) override;
	virtual void Visit(Circle const& circle) override;
	virtual void Visit(Triangle const& triangle) override;
	virtual void Visit(Diamond const& diamond) override;
	virtual void Visit(Polygon const& polygon) override;
};