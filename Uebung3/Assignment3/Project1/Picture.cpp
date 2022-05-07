#include"Polygon.h"
#include"LinkedList.h"
#include"Drawing.h"
#include"Picture.h"

#define _USE_MATH_DEFINES

#include<cmath>

Picture::Picture() {

}

Picture::Picture(Picture& p) {

}

Picture& Picture::operator=(Picture& p) {

}

Picture::~Picture() {

}

void Picture::add(Polygon& p) {

}

void Picture::draw(double x, double y, double w, double h, double f) {
	Polygon frame(0);
	frame.add(0, 0);
	frame.add(0, h);
	frame.add(w, h);
	frame.add(w, 0);
	frame.draw(x,y,f);
}