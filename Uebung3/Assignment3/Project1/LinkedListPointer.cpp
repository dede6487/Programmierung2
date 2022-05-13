//******************************************************************
// "LinkedListPointer.h"
// 
// contains the methods of the class "LinkedListPointer" based on the
// functionality as presented in the lecture slides.
// 
// created by Felix Dressler, 11.05.2022
//******************************************************************

#include"LinkedListPointer.h"
#include"Polygon.h"

#include<iostream>

using namespace std;

//Node Element of the Linked List
class LinkedListPointer::PointerNode {
    friend class LinkedListPointer;  
private:
    Polygon* value; PointerNode* next;
    PointerNode(Polygon* v, PointerNode* n) {
        next = n;
        value = v;
    }
};

//constructor
LinkedListPointer::LinkedListPointer() {
    head = 0;
    number = 0;
}

//destructor
LinkedListPointer::~LinkedListPointer() {
    PointerNode* node = head;
    while (node != 0) {
        PointerNode* node0 = node->next;
        delete node;
        node = node0;
    }
}

//gives the number of nodes in the linked list
int LinkedListPointer::length() const {
    return number;
}

//inserts a Node into the linked list
LinkedListPointer& LinkedListPointer::insert(Polygon* e) {
    PointerNode* node = new PointerNode(e, head);
    head = node;
    number = number + 1;
    return *this;
}

//gives back the value of the element of the linked list in position i
Polygon* LinkedListPointer::get(int i) const {
    PointerNode* node = head;
    for (int j = 0; j < number - i - 1; j++)
        node = node->next;
    return node->value;
}