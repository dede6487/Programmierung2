#pragma once

#include"LinkedList.h"
#include"Polygon.h"

class Picture
{
private:
    LinkedList Polygons;//needs another type
public:
    Picture();
    Picture(Picture& p);
    Picture& operator=(Picture& p);
    ~Picture();
    void add(Polygon& p);
    void draw(double x, double y, double w, double h, double f = 1.0);
};