//******************************************************************
// "Polygon.cpp"
// 
// contains the methods of the class "Polygon", "RegularPolygon",
// "Square" and "Hexagon".
// 
// created by Felix Dressler, 
//******************************************************************

#include"Polygon.h"
#include"LinkedList.h"
#include"Drawing.h"

#define _USE_MATH_DEFINES

#include<cmath>
#include<iostream>

using namespace std;
using namespace compsys;

//constructor for Polygon
Polygon::Polygon(unsigned int color) {
    this->color = color;
    this->points;
}

//copy constructor for polygon
Polygon::Polygon(Polygon& p) {
    this->color = p.color;
    int length = p.points.length();

    for (int i = 0; i < length; i++) {
        this->add(p.points.get(i, 0), p.points.get(i, 1));
    }
}

//copy assignment operator for Polygon
Polygon& Polygon::operator=(Polygon& p) {

    //check if it is already the same

    this->color = p.color;
    int length = p.points.length();

    for(int i = 0; i < length; i++) {
        this->add(p.points.get(i, 0), p.points.get(i, 1));
    }


    return *this;
}

//destructor for Polygon (in this case there is nothing to be deallocated)
Polygon::~Polygon() {
    
}

//******************************************************************
// "clone()"
// 
// virtual function clone, that creates a heap allocated clone
// of a polygon.
//******************************************************************
Polygon* Polygon::clone() {
    cout << "clone - Polygon" << endl;
    Polygon* p = new Polygon(this->color);

    int length = this->points.length();

    for (int i = 0; i < length; i++) {
        p->add(this->points.get(i,0), this->points.get(i, 1));
    }
    
    return p;
}

//******************************************************************
// "add"
// 
// is a method of the "Polygon" class. It adds a point to a polygon.
//******************************************************************
void Polygon::add(double x, double y) {
    int e[2] = { x,y };
    points.insert(e);
}

//******************************************************************
// "draw()"
// 
// is a method of Polygon. It draws a Polygon with the left upper
// point of the surrounding square at (x0,y0) by using the drawPolygon()
// function defined in "Drawing.cpp".
//******************************************************************
void Polygon::draw(double x0, double y0, double f) {
    cout << "draw - Polygon" << endl;
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

//******************************************************************
// constructor of "RegularPolygon"
// 
// 
//******************************************************************
RegularPolygon::RegularPolygon(double x, double y, 
    double r, int n, double a, unsigned int c):Polygon(c) {

    for (double i = 0; i < n; i ++) {
        this->add(x - (cos(a + i * 2 * M_PI / n) * r), y - (sin(a + i * 2 * M_PI / n) * r));
    }
    this->x = x;
    this->y = y;
    this->a = a;
    this->r = r;
    setColor(c);
}

void RegularPolygon::draw(double x0, double y0, double f) {
    cout << "draw - Regular Polygon" << endl;
    Polygon::draw(x0,y0,f);
    drawPoint(x0 + x, y0 + y, getColor());
}
    
//destructor for Polygon (in this case there is nothing to be deallocated)
RegularPolygon::~RegularPolygon() {

}

RegularPolygon* RegularPolygon::clone() {
    cout << "clone - Regular Polygon" << endl;
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



