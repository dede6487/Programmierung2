//******************************************************************
// "LinkedListPointer.h"
// 
// contains the class "LinkedListPointer", that implements a linked list
// based on the linked list that was presented in the lecture slides.
// 
// created by Felix Dressler, 
//******************************************************************

#pragma once

#include"Polygon.h"

class LinkedListPointer
{
    class PointerNode;
private:
    PointerNode* head;
    int number; //starts with 0 for the first element
public:
    LinkedListPointer();
    ~LinkedListPointer();

    int length() const;
    LinkedListPointer& insert(Polygon* e);
    Polygon* get(int i) const;
};