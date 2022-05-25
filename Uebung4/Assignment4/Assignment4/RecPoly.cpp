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
            if (!(coeff[i]->operator==(coeff[i]->zero()))) {
                str += coeff[i]->str() + "*" + var + "^" + to_string(i);
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

    for (int i = 0; i < this->n; i++) {
        this->coeff[i] = this->coeff[i]->operator-();
    }

    return this;
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
        int n_temp = 0;

        if (this->n >= x->n) {
            n_temp = this->n;
        }
        else {
            n_temp = x->n;
        }

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
                    temp[i] = this->coeff[i]->operator+(x->coeff[i]);//why???
                }
            }
            else if(this->n < x->n) {
                for (int i = this->n; i < x->n; i++) {
                    temp[i] = this->coeff[i]->operator+(x->coeff[i]);
                }
            }

            RecPoly* add = new RecPoly(this->var, n_temp, temp);

            return add;
/*          Ring* zer = this->coeff[0]->zero();
            int new_n = 0;

            for (int i = n_temp-1; i > 0; i--) {
                if (temp[i] == zer) {
                    new_n++;
                }
            }
            if (new_n < n_temp) {
                Ring** new_temp = new Ring*[n_temp - new_n];
                for (int i = 0; i < n_temp - new_n; i++) {
                    new_temp[i] = temp[i];
                }
                RecPoly* add = new RecPoly(this->var, n_temp - new_n, new_temp);

                for (int i = 0; i < n_temp; i++) {
                    delete temp[i];
                }
                delete[] temp;

                for (int i = 0; i < n_temp- new_n; i++) {
                    delete new_temp[i];
                }
                delete[] new_temp;

                return add;

            }
            else {
                RecPoly* add = new RecPoly(this->var, n_temp, temp);

                for (int i = 0; i < n_temp; i++) {
                    delete temp[i];
                }
                delete[] temp;

                return add;
            }      */    
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

            cout << "after 0" << endl;

            int length = this->n + x->n - 1;

            Ring** temp = new Ring*[length];

            for (int i = 0; i < length; i++) {
                temp[i] = x->coeff[0]->zero();
                cout << "intitializing temp" << endl;
            }

            for (int i = 0; i < this->n; i++) {
                cout << "in for i" << endl;
                for (int j = 0; j < x->n; j++) {
                    cout << "in for j" << endl;
                    Ring* del = temp[i+j];
                    //cout << x- << endl;
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
    
    for (int i = 0; i < this->n; i++) {
        if (this->coeff[i] != c) {
            return false;
        }
    }
    return true;
}