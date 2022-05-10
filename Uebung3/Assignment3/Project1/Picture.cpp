#include"Polygon.h"
#include"LinkedListPointer.h"
#include"Drawing.h"
#include"Picture.h"

#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

Picture::Picture() {
	h = 200;
	w = 200;
}

Picture::Picture(Picture& p) {
	this->h = p.h;
	this->w = p.w;

	int length = Polygons.length();
	for (int i = 0; i < length; i++) {
		this->Polygons.insert(*p.Polygons.get(i));
	}
}

//copies pointers not values, needs to be changed
Picture& Picture::operator=(Picture& p) {
	this->h = p.h;
	this->w = p.w;

	int length = Polygons.length();
	for (int i = 0; i < length; i++) {
		this->Polygons.insert(*p.Polygons.get(i));
	}

	return *this;
}

Picture::~Picture() {

}

void Picture::add(Polygon &p) {
	cout << "insert" << endl;
	//proble, is here, doesn*t copy correct, missing points for drawing
	this->Polygons.insert(*p.clone());
}

void Picture::draw(double x, double y, double w, double h, double f) {
	Polygon frame(0);
	frame.add(0, 0);
	frame.add(0, h);
	frame.add(w, h);
	frame.add(w, 0);
	frame.draw(x,y,f);

	int length = Polygons.length();

	//for (int i = 0; i < length; i++) {
		cout << "vor draw"<<endl;
		Polygons.get(0)->draw(x,y,f);
	//}
}