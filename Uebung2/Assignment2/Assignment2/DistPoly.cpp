#include"DistPoly.h"
#include<iostream>

using namespace std;

int sort(DistPoly& p, int* exps) {

    return 0;
}

//requires rework
DistPoly& DistPoly::add(int coeff, int* exps) {
    if (coeff !=0) {
        bool added = false;
        for (int j = 0; j < this->m; j++) { //steps through every single monomial that is already existing in this polynomial
            int same = 0;
            for (int i = 0; i < this->n; i++) { //checks every exponent of a polynomial if it is equivalent to the given one, if not same will increase by one
                if (this->monoms[j].exps[i] != exps[i]) {
                    same++;
                }
            }
            if (same == 0) { //if same wasn't increased, the monomial has the same exponents, the coefficients can thus be added together and the for will break
                this->monoms[j].coeff += coeff;
                added = true;
                break;
            }
        }
        //adding above works
        //adding below requires rework
        if (added == false) { //if no exponents were matching, we will create a new monomial and add it to the polynomial

            if (this->m == this->am) {
                this->resize(2);
            }

            int y = this->sort(exps);

            for (int i = y; i <= this->am; i++) {
                this->monoms[i+1].coeff = this->monoms[i].coeff;
                this->monoms[i+1].exps = this->monoms[i].exps;
            }

            this->monoms[y].coeff = coeff;
            this->monoms[y].exps = exps;

        }
    }


    return *this;
}

DistPoly& DistPoly::add(DistPoly& p) {

    return *this;
}

int DistPoly::sort(int* exps) {
    int j = 0, k=0;
    for (int i = 0;true ; i++) {
        if (exps[j] == this->monoms[i].exps[j]) {
            //now we must compare the next exponent and see if it is greater or not
            break;
        }
        else if (exps[j] > this->monoms[i].exps[j]) {
            return i;
            break;
        }
    }
}

void DistPoly::println_brkts() {
    if (n == 0) {
        cout << "0" << endl;
    }
    else {
        cout << "vars = ";
        for (int i = 0; i < n; i++) {
            cout << this->vars[i];
        }
        cout << "\n";
        cout << "Polynomial = [";
        for (int i = 0; i < m; i++) {
            cout << "{";
            cout << this->monoms[i].coeff << ", ";
            cout << "(";
            for (int j = 0; j < n; j++) {
                cout << this->monoms[i].exps[j];
                cout << " ,";
            }
            cout << ")";
            cout << "}, ";
        }
        cout << "]" << endl;
    }
}

void DistPoly::println() {
    int empty = 0;
    if (n == 0 || m==0) {
        cout << "0" << endl;
    }
    else {
        for (int i = 0; i < m; i++) {
            if (this->monoms[i].coeff != 0) {
                cout << this->monoms[i].coeff;
                cout << "*";
                for (int j = 0; j < n; j++) {
                    cout << this->vars[j];
                    cout << "^" << this->monoms[i].exps[j];
                    if (j == n - 1 && i < am-1) cout << "+";
                }
            }
            else {
                empty++;
            }
        }
        if (empty == m) {
            cout << "0";
        }
        cout << "\n";
    }
}

DistPoly::DistPoly(int n, string* vars) {
    this->n = n;
    this->vars = vars;
    this->m = 1;
    this->am = 0;
    this->monoms = new Monom[m];
    for (int j = 0; j < m; j++) {
        this->monoms[j].coeff = 0;
        this->monoms[j].exps = new int[n];
        for (int i = 0; i < n; i++) {
            this->monoms[j].exps[i] = 0;
        }
    }
}

DistPoly::DistPoly(DistPoly& p) {
    this->n = p.n;
    this->vars = p.vars;
    this->m = p.m;
    this->am = p.am;
    this->monoms = new Monom[(p.m) + 1];
    for (int i = 0; i < m; i++) {
        this->monoms[i].coeff = p.monoms[i].coeff;
        this->monoms[i].exps = p.monoms[i].exps;
    }

}

//does this even work?
DistPoly& DistPoly::operator=(DistPoly& p) {
    this->n = p.n;
    this->vars = p.vars;
    this->m = p.m;
    this->am = p.am;
    this->monoms = new Monom[(p.m) + 1];
    for (int i = 0; i < m; i++) {
        this->monoms[i].coeff = p.monoms[i].coeff;
        this->monoms[i].exps = p.monoms[i].exps;
    }
    return *this;
}

//constructor for Monom, problem is because it tries to delete a pointer, that has already been deleted
DistPoly::~DistPoly() {
    //for (int i = 0; i < this->m; i++) {
    //    delete[] this->monoms[i].exps;
    //}
    delete[] this->monoms;
}

void DistPoly::resize(int factor) {
    Monom* NewMonoms = new Monom[factor * m];
    for (int i = 0; i < this->m; i++) {
        NewMonoms[i] = this->monoms[i];
    }
    for (int i = this->m; i < (this->m) * factor; i++) {//initializes the remaining elements of the array with the standard value 0
        NewMonoms[i].coeff = 0;
        NewMonoms[i].exps = new int[this->n];
        for (int j = 0; j < this->n; j++) {
            NewMonoms[i].exps[j] = 0;
        }
    }
    delete[] this->monoms;
    this->monoms = NewMonoms;
    this->m = factor * (this->m);
}
//constructor
//Monom::Monom(int coeff, int* exps, int n) {
//    this->coeff = coeff;
//    this->exps = new int[n]; //creates a new array of exponents, this is in order to have seperate pointers and deallocate their respectivve memory later (for DistPoly)
//    this->exps = exps;
//}
//
//
////constructor
//Monom::Monom(int n) {
//    this->coeff = 0;
//    this->exps = new int[n];
//}
//
//
////copy assignment operator
//Monom& Monom::operator=(Monom& m) {
//    this->coeff = m.coeff;
//    this->exps = m.exps;
//
//    return *this;
//}