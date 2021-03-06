//******************************************************************
// "Integer.cpp"
//
// implements the functionality of the class Integer with its
// Ring operations
// 
// created by: Felix Dressler - 24.05.2022
//******************************************************************

#include"Integer.h"
#include<iostream>

using namespace std;

// integer with value n (default 0)
Integer::Integer(int n) {
    this->n = n;
}

// a heap-allocated duplicate of this element
Ring* Integer::clone() {
    Integer* c = new Integer(this->n);
    
    return c;
}

// the string representation of this element
string Integer::str() {

    return to_string(this->n);;
}

// the constant of the type of this element and the inverse of this element
Ring* Integer::zero() {

    return new Integer(0);
}

Ring* Integer::operator-() {

    return new Integer(-(this->n));
}

// sum and product of this element and c
Ring* Integer::operator+(Ring* c) {
    Integer* x = dynamic_cast<Integer*>(c);

    //if cast is unsuccessful, we exit
    if (x == 0) {
        cout << "Error: Addition with incompatible Elements performed" << endl;
        exit(1);
    }

    int t = this->n + x->n;
    
    return new Integer(t);
}

Ring* Integer::operator*(Ring* c) {
    Integer* x = dynamic_cast<Integer*>(c);

    //if the cast is unsuccessful, we exit 
    if (x == 0) {
        cout << "Error: Multiplikation with incompatible Elements performed" << endl;
        exit(2);
    }

    return new Integer(this->n * x->n);
}

// comparison function
bool Integer::operator==(Ring* c) {
    Integer* x = dynamic_cast<Integer*>(c);


    //if cast is unsuccessful, we exit
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