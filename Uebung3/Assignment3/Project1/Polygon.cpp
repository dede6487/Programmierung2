#include"Polygon.h"
#include"LinkedList.h"
#include"Drawing.h"

using namespace std;

//constructor
Polygon::Polygon(unsigned int color = 0) {
    this->color = color;
}

Polygon::Polygon(Polygon& p) {

}

Polygon& Polygon::operator=(Polygon& p) {

}

Polygon::~Polygon() {

}

Polygon* Polygon::clone() {

}

void Polygon::add(double x, double y) {

}

void Polygon::draw(double x0 = 0, double y0 = 0, double f = 1) {
    //beginDrawing(x0*3, y0*3, "Polygon",0xFFFF, false);
    drawPolygon(, x0, y0, color);

    //endDrawing();
}