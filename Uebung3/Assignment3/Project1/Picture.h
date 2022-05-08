#pragma once

#include"LinkedListPointer.h"
#include"Polygon.h"

class Picture
{
private:
    LinkedListPointer Polygons;
    unsigned int h;
    unsigned int w;
public:
    Picture();
    Picture(Picture& p);
    Picture& operator=(Picture& p);
    ~Picture();
    void add(Polygon& p);
    void draw(double x, double y, double w, double h, double f = 1.0);
};