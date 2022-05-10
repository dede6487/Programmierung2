#include"Polygon.h"
#include"Drawing.h"
#include"Picture.h"

#include<iostream>

using namespace std;

using namespace compsys;

//#include"Drawing.h"

int main() {
	Polygon p(100);

	beginDrawing(500, 500, "Polygon", 0xFFFFFF, false);

	p.add(1, 1);
	p.add(50, 1);
	p.add(50, 50);
	p.add(1, 50);

	//p.draw();

	Polygon l(0);

	//l = *p.clone();

	//l.draw(20,20);


	RegularPolygon q(250, 250, 30, 5, 0, 100);

	//q.draw();

	Square r(350, 350, 60, 0, 0xFF);

	//r.draw();

	Hexagon s(400,200,80,0,0x00FF);

	//s.draw();

	Picture pic;

	cout << "add p - Polygon" << endl;
	pic.add(p);
	cout << "add q - Regular" << endl;
	pic.add(q);
	cout << "add r - Regular" << endl;
	pic.add(r);
	cout << "add s - Regular" << endl;
	pic.add(s);

	pic.draw(40,40,300,300,1);

	endDrawing();
}