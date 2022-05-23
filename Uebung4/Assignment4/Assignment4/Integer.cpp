#include"Integer.h"
#include<iostream>

using namespace std;

// integer with value n (default 0)
Integer::Integer(int n) {
    this->n = n;
}

// a heap-allocated duplicate of this element
Integer* Integer::clone() {
    Integer* c = new Integer(this->n);
    
    return c;
}

// the string representation of this element
string Integer::str() {

    return to_string(this->n);;
}

// the constant of the type of this element and the inverse of this element
Integer* Integer::zero() {

    return new Integer(0);
}

Integer* Integer::operator-() {

    return new Integer(-(this->n));
}

// sum and product of this element and c
Integer* Integer::operator+(Ring* c) {
    Integer* x = dynamic_cast<Integer*>(c);

    if (x == 0) {
        cout << "Error: Addition with incompatible Elements performed" << endl;
        exit(1);
    }

    return new Integer(this->n + x->n);
}

Integer* Integer::operator*(Ring* c) {
    Integer* x = dynamic_cast<Integer*>(c);

    if (x == 0) {
        cout << "Error: Multiplikation with incompatible Elements performed" << endl;
        exit(2);
    }

    return new Integer(this->n * x->n);
}

// comparison function
bool Integer::operator==(Ring* c) {
    Integer* x = dynamic_cast<Integer*>(c);

    if (x == 0) {
        cout << "Error: Comparison with incompatible Elements performed" << endl;
        exit(3);
    }

    if (this->n == x->n) {
        return true;
    }
    else {
        return false;
    }

}