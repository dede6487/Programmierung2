#include"RecPoly.h"
#include"Integer.h"


// polynomial with n>=0 coefficients and given variable name
RecPoly::RecPoly(string var, int n, Ring** coeffs) {
    this->var = var;
    this->n = n;
    this->coeff = new Ring*[n];
    for (int i = 0; i < n; i++) {
        coeff[i] = coeffs[i]->clone();//clone to make sure only we have control over the array
    }
}

// copy constructor, copy assignment operator, destructor
RecPoly::RecPoly(RecPoly& p) {
    this->var = p.var;
    this->n = p.n;

    this->coeff = new Ring * [n];
    for (int i = 0; i < n; i++) {
        coeff[i] = p.coeff[i]->clone();
    }
}

RecPoly& RecPoly::operator=(RecPoly& p) {
    this->var = p.var;
    this->n = p.n;

    this->coeff = new Ring * [n];
    for (int i = 0; i < n; i++) {
        coeff[i] = p.coeff[i]->clone();
    }

    return *this;
}

RecPoly::~RecPoly() {
    for (int i = 0; i < this->n;i++) {
        delete coeff[i];
    }
    delete[] coeff;
}

// a heap-allocated duplicate of this element
Ring* RecPoly::clone() {

    return new RecPoly(*this);
}

// the string representation of this element
string RecPoly::str() {
    string str = "";
    if (n == 0) {
        str = "0";
    }
    else {
        str += "(";
        for (int i = 0; i < n; i++) {
            str += coeff[i]->str() + "*" + var + "^" + to_string(i);
            if (i < n - 1) {
                str += "+";
            }
        }
        str += ")";
    }

    return str;
}

// the constant of the type of this element and the inverse of this element
Ring* RecPoly::zero() {
    return new RecPoly(this->var, 0, {});
}

Ring* RecPoly::operator-() {

    for (int i = 0; i < this->n; i++) {
        this->coeff[i] = this->coeff[i]->operator-();
    }

    return this;
}

// sum and product of this element and c
Ring* RecPoly::operator+(Ring* c) {

    Ring** temp = new Ring*[this->n];

    for (int i = 0; i < this->n; i++) {
        temp[i] = c->operator+(this->coeff[i]);//important
    }

    RecPoly* add = new RecPoly(this->var, this->n, temp);

    //for (int i = 0; i < this->n; i++) {
    //    delete temp[i];
    //}
    //delete[] temp;

    return add;
}

Ring* RecPoly::operator*(Ring* c) {
    if (this->n == 0) {
        return new RecPoly(*this);
    }
    else{
        Ring** temp = new Ring*[this->n];
        for (int i = 0; i < this->n; i++) {
            temp[i] = 0;
            for (int j = 0; j < i; j++) {
                temp[i] = temp[i]->operator+(c->operator*(this->coeff[i]));
            }
        }

        RecPoly* mult = new RecPoly(this->var, this->n, temp);

        //for (int i = 0; i < this->n; i++) {
        //    delete temp[i];
        //}
        //delete[] temp;

        return mult;
    }
}

// comparison function
bool RecPoly::operator==(Ring* c) {
    
    for (int i = 0; i < this->n; i++) {
        if (this->coeff[i] != c) {
            return false;
        }
    }
    return true;
}