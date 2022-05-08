#include"Polygon.h"
#include"LinkedList.h"
#include"Drawing.h"

#define _USE_MATH_DEFINES

#include<cmath>

using namespace std;
using namespace compsys;

//constructor
Polygon::Polygon(unsigned int color) {
    this->color = color;
    this->points;
}

Polygon::Polygon(Polygon& p) {
    this->points = p.points;
    this->color = p.color;
}

Polygon& Polygon::operator=(Polygon& p) {
    this->points = p.points;
    this->color = p.color;

    return *this;
}

Polygon::~Polygon() {
    
}

Polygon* Polygon::clone() {
    Polygon* p = new Polygon(this->color);

    int length = this->points.length();

    for (int i = 0; i < length; i++) {
        p->add(this->points.get(i,0), this->points.get(i, 1));
    }
    
    return p;
}

void Polygon::add(double x, double y) {
    int e[2] = { x,y };
    points.insert(e);
}

void Polygon::draw(double x0, double y0, double f) {
    int length = points.length();
    int* tempx = new int[length];
    int* tempy = new int[length];

    for (int i = 0; i < length; i++) {
        tempx[i] = x0 + points.get(i,0)*f;
        tempy[i] = y0 + points.get(i, 1)*f;
    }

    drawPolygon(length, tempx, tempy, color);

    delete[] tempx;
    delete[] tempy;  
}

//*************************************************************************************************

RegularPolygon::RegularPolygon(double x, double y, 
    double r, int n, double a, unsigned int c):Polygon(c) {

    for (double i = 0; i < n; i ++) {
        this->add(x - (cos(a + i * 2 * M_PI / n) * r), y - (sin(a + i * 2 * M_PI / n) * r));
    }
    this->x = x;
    this->y = y;
    this->n = n;
    this->a = a;
    this->r = r;
    setColor(c);
}

void RegularPolygon::draw(double x0, double y0, double f) {
    Polygon::draw(x0,y0,f);
    drawPoint(x0 + x, y0 + y, getColor());
}
    
RegularPolygon::~RegularPolygon() {

}

RegularPolygon* RegularPolygon::clone() {
    RegularPolygon* p = new RegularPolygon(this->x, this->y, this->r, this->pNum(), this->a, this->getColor());

    return p;
}

//*************************************************************************************************

Square::Square(double x, double y, 
    double r, double a, unsigned int c):RegularPolygon(x,y,r,4,a,c) {

}

//*************************************************************************************************

Hexagon::Hexagon(double x, double y, 
    double r, double a, unsigned int c) :RegularPolygon(x, y, r, 6, a, c) {

}

//*************************************************************************************************