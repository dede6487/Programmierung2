#include"Polygon.h"
#include"LinkedList.h"
#include"Drawing.h"
#include"Picture.h"

#define _USE_MATH_DEFINES

#include<cmath>

Picture::Picture() {
	h = 200;
	w = 200;
}

Picture::Picture(Picture& p) {
	this->h = p.h;
	this->w = p.w;
	this->Polygons = p.Polygons;
}

Picture& Picture::operator=(Picture& p) {
	this->h = p.h;
	this->w = p.w;
	this->Polygons = p.Polygons;

	return *this;
}

Picture::~Picture() {

}

void Picture::add(Polygon &p) {
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

	for (int i = 0; i < length; i++) {
		Polygons.get(i)->draw(x,y,f);
	}
}