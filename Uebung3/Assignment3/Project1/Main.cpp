#include"Polygon.h"
#include"Drawing.h"

using namespace compsys;

//#include"Drawing.h"

int main() {
	Polygon p(100);

	beginDrawing(500, 500, "Polygon", 0xFFFFFF, false);

	p.add(1, 1);
	p.add(50, 1);
	p.add(50, 50);
	p.add(1, 50);

	p.draw();

	RegularPolygon q(250, 250, 30, 5, 0, 100);

	q.draw();

	Square r(350, 350, 60, 0, 0xFF);

	r.draw();

	Hexagon s(400,200,80,0,0x00FF);

	s.draw();

	endDrawing();
}