#include"DistPoly.h"
#include<iostream>

using namespace std;

DistPoly& DistPoly::add(int coeff, int* exps) {
    if (coeff !=0) {
        for (int j = 0; j <= this->m; j++) {
            
            int k = 1;
            if (j < this->m) {
                k = sort(exps, this->n, j);
            }
            if (k == 0) {
                this->monoms[j].coeff += coeff;
                break;
            }
            else if (k == -1) {

                this->resize(2);

                for (int l = j; l < this->am+1; l++) {
                    this->monoms[l + 1] = this->monoms[l];
                }
                this->monoms[j].coeff = coeff;
                this->monoms[j].exps = exps;
                this->am++;
                break;
            }
        }
    }

    return *this;
}

DistPoly& DistPoly::add(DistPoly& p) {

    return *this;
}

int DistPoly::sort(int* exps, int n, int j) {
    for (int i = 0; i < n; i++) {
        if (this->monoms[j].exps[i] > exps[i]) {
            return 1;
        }
         else if (this->monoms[j].exps[i] < exps[i]) {
            return -1;
        }
    }
    return 0;
}

//

void DistPoly::println() {
    int empty = 0;
    if (n == 0 || m==0 || am==0) {
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
                    if (j == this->n && i < am) cout << "+";
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