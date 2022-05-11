//******************************************************************
// "Main.cpp"
// 
// is used to test the functions of the "Polygon" class and its derived
// classes. Further it also contains functions to test the class "Picture"
// 
// created by Felix Dressler, 11.05.2022
//******************************************************************

#include"Polygon.h"
#include"Drawing.h"
#include"Picture.h"

#include<iostream>

using namespace std;

using namespace compsys;


int main() {
	Polygon p(100);

	beginDrawing(500, 500, "Polygon", 0xFFFFFF, false);

	p.add(1, 1);
	p.add(50, 1);
	p.add(50, 50);
	p.add(1, 50);

	p.draw();

	Polygon l(0);

	l = *p.clone();

	l.draw(60,60);


	RegularPolygon q(250, 250, 30, 5, 0, 100);

	q.draw();

	RegularPolygon a(0,0,0,0,0,0);

	a = *q.clone();

	a.draw(50, 50);

	//Square r(350, 350, 60, 0, 0xFF);

	////r.draw();

	//Hexagon s(400,200,80,0,0x00FF);

	////s.draw();

	//Picture pic;

	//cout << "add p - Polygon" << endl;
	//pic.add(p);
	//cout << "add q - Regular" << endl;
	//pic.add(q);
	//cout << "add r - Regular" << endl;
	//pic.add(r);
	//cout << "add s - Regular" << endl;
	//pic.add(s);

	//pic.draw(40,40,300,300,1);

	endDrawing();
}