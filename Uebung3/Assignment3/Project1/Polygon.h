//******************************************************************
// "Polygon.h"
// 
// contains the classes "Plygon", "RegularPolygon", "Square" and 
// "Hexagon", which all create polygons. The names of the classes
// are already self explanatory.
// 
// created by Felix Dressler, 10.05.2022
//******************************************************************

#pragma once

#include"LinkedList.h"

//******************************************************************
// "Polygon.h"
// 
// holds a linked list of points of a Polygon and the color of the
// outline of the polygon.
//******************************************************************
class Polygon
{
private:
    unsigned int color = 0xFFFF;
    LinkedListArr points;

public:
    // create polygon in denoted color (default black)
    Polygon(unsigned int color = 0);

    // copy constructor, copy assignment operator, destructor
    Polygon(Polygon& p);
    Polygon& operator=(Polygon& p);
    virtual ~Polygon();

    // create a heap-allocated copy of this polygon
    virtual Polygon* clone();

    // add point with relative coordinates (x,y) to polygon
    void add(double x, double y);

    // draws the polygon at absolute coordinates (x0,y0) scaled by factor f;
    // thus every point (x,y) is drawn at position (x0+x*f, y0+y*f)
    void draw(double x0 = 0, double y0 = 0, double f = 1);

    //sets the color of the polygon
    void setColor(unsigned int c){
        this->color = c; 
    }
    
    //gives back the color of the polygon
    unsigned int getColor() {
        return color;
    }

    //gives back the number of points in the polygon
    int pNum() {
        return points.length();
    }

    //gives back the specific coordinate x (n=0) or y (n=1) for a point of Polygon
    int getCoord(int i, int n) {
        return points.get(i, n);
    }
};


//******************************************************************
// "Polygon.h"
// 
// constructs a special case of a polygon, a regular polygon.
// It additionally holds an angle a, x and y middle-point coordinates
// and a radius.
//******************************************************************
class RegularPolygon : public Polygon
{
private:
    double a;
    double x;
    double y;
    double r;
public:
    //constructor
    RegularPolygon(double x, double y, double r, int n,
        double a = 0, unsigned int c = 0);

    //destructor
    ~RegularPolygon();

    //draws a regular polygon
    void draw(double x0 = 0, double y0 = 0, double f = 1);

    //clones a regular polygon
    RegularPolygon* clone();
};


//******************************************************************
// "Polygon.h" and "Hexagon"
// 
// constructs two special cases of a regular polygon by fixing 
// the number of points to 4/6.
//******************************************************************
class Square : public RegularPolygon
{
public:
    //constructs a square
    Square(double x, double y, double r,
        double a = 0, unsigned int c = 0);
};

class Hexagon : public RegularPolygon
{
public:
    //constructs a hexagon
    Hexagon(double x, double y, double r,
        double a = 0, unsigned int c = 0);
};