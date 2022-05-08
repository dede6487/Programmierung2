#include"LinkedListPointer.h"
#include"Polygon.h"

class LinkedListPointer::PointerNode {
    friend class LinkedListPointer;
private:
    Polygon* value; PointerNode* next;
    PointerNode(Polygon* v, PointerNode* n) {
        next = n;
        value = v;
    }
};

LinkedListPointer::LinkedListPointer() {
    head = 0;
    number = 0;
}

LinkedListPointer::~LinkedListPointer() {
    PointerNode* node = head;
    while (node != 0) {
        PointerNode* node0 = node->next;
        delete node;
        node = node0;
    }
}

int LinkedListPointer::length() const {
    return number;
}
LinkedListPointer& LinkedListPointer::insert(Polygon e) {
    PointerNode* node = new PointerNode(&e, head);
    head = node;
    number = number + 1;
    return *this;
}
Polygon* LinkedListPointer::get(int i) const {
    PointerNode* node = head;
    for (int j = 0; j < number - i - 1; j++)
        node = node->next;
    return node->value;
}