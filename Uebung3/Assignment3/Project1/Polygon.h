#pragma once

//could be unincluded later
#include"LinkedList.h"


class Polygon
{
private:
    unsigned int color = 0xFFFF;
    LinkedList points;

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
};

class RegularPolygon : public Polygon
{
private:
    double a;
    double x;
    double y;
    int n;
    unsigned int c;
    double r;
public:
    RegularPolygon(double x, double y, double r, int n,
        double a = 0, unsigned int c = 0);

    virtual ~RegularPolygon();

    virtual void draw(double x0 = 0, double y0 = 0, double f = 1);
};