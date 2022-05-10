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