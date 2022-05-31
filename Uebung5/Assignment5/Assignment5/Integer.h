#pragma once

#include<string>
#include<iostream>

using namespace std;

class Integer {
private:
	int n;
public:
	// integer with value n (default 0)
	Integer(int n = 0);

	// destructor - empty because in Integer no new arrays/pointers are created
	~Integer() {

	}

	// a heap-allocated duplicate of this element
	Integer* clone();

	// the string representation of this element
	string str();

	// the constant of the type of this element and the inverse of this element
	Integer* zero();
	Integer* operator-();

	// sum and product of this element and c
	Integer* operator+(Integer* c);
	Integer* operator*(Integer* c);

	// comparison function
	bool operator==(Integer* c);
};


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
    //Integer* x = dynamic_cast<Integer*>(c);

    ////if cast is unsuccessful, we exit
    //if (x == 0) {
    //    cout << "Error: Addition with incompatible Elements performed" << endl;
    //    exit(1);
    //}

    int t = this->n + x->n;

    return new Integer(t);
}

Integer* Integer::operator*(Integer* x) {
    //Integer* x = dynamic_cast<Integer*>(c);

    ////if the cast is unsuccessful, we exit 
    //if (x == 0) {
    //    cout << "Error: Multiplikation with incompatible Elements performed" << endl;
    //    exit(2);
    //}

    return new Integer(this->n * x->n);
}

// comparison function
bool Integer::operator==(Integer* x) {
    //Integer* x = dynamic_cast<Integer*>(c);


    ////if cast is unsuccessful, we exit
    //if (x == 0) {
    //    cout << "Error: Comparison with incompatible Elements performed" << endl;
    //    exit(3);
    //}

    if (this->n == x->n) {
        return true;
    }
    else {
        return false;
    }

}