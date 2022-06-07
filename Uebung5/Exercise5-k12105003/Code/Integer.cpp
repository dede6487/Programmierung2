//******************************************************************
// "Integer.cpp"
//
// contains the function definitions of the class Integer.
// 
// created by: Felix Dressler - 03.06.2022
//******************************************************************

#include"Integer.h"

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
Integer* Integer::operator+(Integer* x) {

    int t = this->n + x->n;

    return new Integer(t);
}

Integer* Integer::operator*(Integer* x) {

    return new Integer(this->n * x->n);
}

// comparison function
bool Integer::operator==(Integer* x) {

    if (this->n == x->n) {
        return true;
    }
    else {
        return false;
    }

}