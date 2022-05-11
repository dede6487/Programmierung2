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
	beginDrawing(600, 600, "Polygon", 0xFFFFFF, false);

	Polygon p(100);
	p.add(1, 1);
	p.add(50, 1);
	p.add(50, 50);
	p.add(1, 50);
	p.draw();//testin polygon draw


	Polygon l(0);
	l = *p.clone();//testing polygon clone
	l.draw(0,60);

	Polygon w(p);//testing copy constructor
	w.draw(450,0);

	Polygon z(0);
	z = w;//testing copy assignment operator
	z.draw(450, 50);

	RegularPolygon q(80, 80, 30, 5, 0, 100);
	q.draw();//testing regular polygon draw

	RegularPolygon a(0,0,0,0,0,0);
	a = *q.clone();//testing regular polygon clone
	a.draw(0, 100);

	RegularPolygon e(0, 0, 0, 0, 0, 0);
	e = q;//testing copy assignment operator
	e.draw(350, 0);

	RegularPolygon f(q);//testing copy constructor
	f.draw(350, 80);

	Square r(120, 120, 60, 0, 0xFF);
	r.draw();

	Hexagon s(200,100,80,0,0x00FF);
	s.draw();

	//testing functions of picture

	Picture pic;

	//cout << "add p - Polygon" << endl;
	pic.add(p);
	//cout << "add q - Regular" << endl;
	pic.add(q);
	//cout << "add r - Regular" << endl;
	pic.add(r);
	//cout << "add s - Regular" << endl;
	pic.add(s);

	pic.draw(280,280,300,300,0.6);

	Picture pic2(pic);

	Picture pic3;

	pic3 = pic;

	pic2.draw(280, 0, 300, 300, 0.4);
	pic3.draw(0, 280, 300, 300, 0.4);


	endDrawing();
}