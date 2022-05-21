#include"Integer.h"
#include<iostream>

using namespace std;

// integer with value n (default 0)
Integer::Integer(int n) {
    this->n = n;
}

// a heap-allocated duplicate of this element
Integer* Integer::clone() {
    Integer c(this->n);
    
    return *c;
}

// the string representation of this element
string Integer::str() {
    string s = to_string(this->n);
    return s;
}

// the constant of the type of this element and the inverse of this element
Integer* Integer::zero() {

}

Integer* Integer::operator-() {

}

// sum and product of this element and c
Integer* Integer::operator+(Integer* c) {
    Integer* x = dynamic_cast<Integer*>(c);

    if (x == 0) {
        cout << "Error: Addition with incompatible Elements performed" << endl;
        exit(1);
    }

    Integer temp(this->n + x->n);

    return *temp;
}

Integer* Integer::operator*(Integer* c) {
    Integer* x = dynamic_cast<Integer*>(c);
    Integer temp(this->n * x->n);

    if (x == 0) {
        cout << "Error: Multiplikation with incompatible Elements performed" << endl;
        exit(2);
    }

        return *temp;
}

// comparison function
bool Integer::operator==(Integer* c) {
    if (this->n == c->n) {
        return true;
    }
    else {
        return false;
    }

}