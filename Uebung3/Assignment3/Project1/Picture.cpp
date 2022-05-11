//******************************************************************
// "Picture.cpp"
// 
// contains the methods of the class "Picture".
// 
// created by Felix Dressler, 
//******************************************************************

#include"Polygon.h"
#include"LinkedListPointer.h"
#include"Drawing.h"
#include"Picture.h"

#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

//constructor for Picture
Picture::Picture() {
    h = 200;
    w = 200;
}

//copy constructor for Picture
Picture::Picture(Picture& p) {
    this->h = p.h;
    this->w = p.w;

    int length = Polygons.length();
    for (int i = 0; i < length; i++) {
        this->Polygons.insert(p.Polygons.get(i));
    }
}

//copy assignment operator for Picture
Picture& Picture::operator=(Picture& p) {
    this->h = p.h;
    this->w = p.w;

    int length = Polygons.length();
    for (int i = 0; i < length; i++) {
        this->Polygons.insert(p.Polygons.get(i));
    }

    return *this;
}

//destructor for Picture
// destructs all heap allocated clones that were created and
// added into the Linked List that Picture holds.
Picture::~Picture() {
    int length = Polygons.length();

    for (int i = 0; i < length; i++) {
        delete Polygons.get(i);
    }
}

//******************************************************************
// "add()"
// 
// adds a Polygon to the linked list of picture by cloning the
// respective polygon. This creates a heap allocated copy of the 
// polygon, which has to be deleted by the destructor of Picture.
//******************************************************************
void Picture::add(Polygon &p) {
    this->Polygons.insert(p.clone());
}

//******************************************************************
// "draw()"
// 
// first draws a frame of width w and heigth h at position (x,y) for
// its upper left corner.
// It then draws the polygons that are held in the linked list at 
// their respective position to (x,y) and resized by a factor f.
// (clipping allowed)
//******************************************************************
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