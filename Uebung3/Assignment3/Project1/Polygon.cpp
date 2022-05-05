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
    beginDrawing(500, 500, "Polygon", 0xFFFF, false);

    for (int i = 0; i < this->points.length() - 1; i++)
    {
        drawLine(xs[i], ys[i], xs[i + 1], ys[i + 1], color);
    }
    if (n > 0) {
        drawLine(xs[this->points.length() - 1], ys[this->points.length() - 1], xs[0], ys[0], color);
    }
    flush();

    endDrawing();
}