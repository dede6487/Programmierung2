//******************************************************************
// "RecPoly.cpp"
//
//
// 
// created by: Felix Dressler - 24.05.2022
//******************************************************************

#include"RecPoly.h"
#include"Integer.h"

#include<algorithm>
#include<iostream>

using namespace std;


// polynomial with n>=0 coefficients and given variable name
RecPoly::RecPoly(string var, int n, Ring** coeffs) {
    this->var = var;

    int zeros = 0;

    //cuts of all 0s at the end of the coeffs array
    if (n != 0) {
        Ring* z = coeffs[0]->zero();

        for (int i = n - 1; i >= 0; i--) {
            if (!(coeffs[i]->operator==(z))) {
                break;
            }
            zeros++;
        }
        delete z;
    }

    this->n = n-zeros;
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

    delete[] this->coeff;
    this->coeff = new Ring*[n];

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
            if (!(coeff[i]->operator==(coeff[i]->zero()))) {
                str += coeff[i]->str();
                if (i != 0) {
                    str += "*" + var + "^" + to_string(i);
                }
                if (i < n - 1) {
                    str += "+";
                }
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

    Ring** temp = new Ring*[this->n];

    for (int i = 0; i < this->n; i++) {
        temp[i] = this->coeff[i]->operator-();
    }

    RecPoly* ret = new RecPoly(this->var, this->n, temp);

    for (int i = 0; i < this->n; i++) {
        delete temp[i];
    }
    delete[] temp;

    return ret;
}

// sum and product of this element and c
Ring* RecPoly::operator+(Ring* c) {

    RecPoly* x = dynamic_cast<RecPoly*>(c);

    if (x == 0) {
        cout << "Error: Addition with incompatible Elements performed" << endl;
        exit(3);
    }
    if (this->var != x->var) {
        cout << "Error: Addition with incompatible Polynomials performed (wrong variables)" << endl;
        exit(4);
    }

    else {
        int n_temp = max(this->n,x->n);

        Ring** temp = new Ring*[n_temp];

        if (this->n == 0) {
            for (int i = 0; i < x->n; i++) {
                temp[i] = x->coeff[i]->clone();
            }

            RecPoly* add = new RecPoly(this->var, x->n, temp);

            for (int i = 0; i < n_temp; i++) {
                delete temp[i];
            }
            delete[] temp;

            return add;
        }
        else {

            for (int i = 0; i < this->n && i < x->n; i++) {
                temp[i] = this->coeff[i]->operator+(x->coeff[i]);
            }

            if (this->n > x->n) {
                for (int i = x->n; i < this->n; i++) {
                    temp[i] = this->coeff[i];
                }
            }
            else if(this->n < x->n) {
                for (int i = this->n; i < x->n; i++) {
                    temp[i] = x->coeff[i];
                }
            }

            RecPoly* add = new RecPoly(this->var, n_temp, temp);

            return add;  
        }
    }


}

Ring* RecPoly::operator*(Ring* c) {

    RecPoly* x = dynamic_cast<RecPoly*>(c);

    if (x == 0) {
        cout << "Error: Multiplication with incompatible Elements performed" << endl;
        exit(5);
    }
    if (this->var != x->var) {
        cout << "Error: Multiplication with incompatible Polynomials performed (wrong variables)" << endl;
        exit(6);
    }

    else {
        if (this->n == 0 || x->n == 0) {
            return this->zero(); // new RecPoly(this->var, 0, {});
        }
        else{

            int length = this->n + x->n -1;

            Ring** temp = new Ring*[length];

            for (int i = 0; i < length; i++) {
                temp[i] = x->coeff[0]->zero();
            }

            for (int i = 0; i < this->n; i++) {
                for (int j = 0; j < x->n; j++) {
                    Ring* del = temp[i+j];
                    temp[i+j] = temp[i+j]->operator+(this->coeff[i]->operator*(x->coeff[j]));
                    delete del;
                }
                
            }

            RecPoly* mult = new  RecPoly(this->var, length, temp);

            for (int i = 0; i < length; i++) {
                delete temp[i];
            }
            delete[] temp;

            return mult;
        }
    }
    
}

// comparison function
bool RecPoly::operator==(Ring* c) {
    
    RecPoly* x = dynamic_cast<RecPoly*>(c);

    bool same = true;

    for (int i = 0; i < this->n; i++) {
        if (this->coeff[i] != x->coeff[i]) {
            same = false;
        }
    }
    return same;
}