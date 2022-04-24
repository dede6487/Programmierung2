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
        for (int j = 0; j <= this->m; j++) { //steps through every single monomial that is already existing in this polynomial
            int same = 0;
            for (int i = 0; i <= this->n; i++) { //checks every exponent of a polynomial if it is equivalent to the given one, if not same will increase by one
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
        if (added == false) { //if no exponents were matching, we will create a new monomial and add it to the polynomial
            //if (this->m == this->am) {
            //    Monom* NewMonoms = new Monom[2 * (this->m)];
            //    for (int i = 0, j = 0; i <= m && j<=n; i++) {
            //        if (this->monoms[i].exps[j] > exps[j]) {
            //            NewMonoms[i] = this->monoms[i];
            //        }
            //        else if(this->monoms[i].exps[j] == exps[j]) {
            //            j++;  
            //        }
            //        else if (this->monoms[i].exps[j] < exps[j]) {
            //            NewMonoms[i].coeff = coeff;
            //            NewMonoms[i].exps = exps;
            //            for (int k = i+1; k <= m + 1; k++) {//copys every other monom after the inserted monom, then breaks
            //                NewMonoms[k] = this->monoms[k];
            //            }
            //            break;
            //        }
            //    }
            //}
        }
    }

    return *this;
}

DistPoly& DistPoly::add(DistPoly& p) {

    return *this;
}

void DistPoly::println() {
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
        for (int i = 0; i <= m; i++) {
            cout << "{";//different symbol?
            cout << this->monoms[i].coeff << ", ";
            for (int j = 0; j <= n; j++) {
                cout << this->monoms[i].exps[j];
            }
            cout << "}, ";//different symbol?
        }
        cout << "]" << endl;
    }
}

DistPoly::DistPoly(int n, string* vars) {
    this->n = n;
    this->vars = vars;
    this->m = 1;
    this->am = 0;
    this->monoms = new Monom[m+1];
    for (int j = 0; j <= m; j++) {
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
    this->monoms = new Monom[(p.m)+1];
    for (int i = 0; i <= m; i++) {
        this->monoms[i].coeff = p.monoms[i].coeff;
        this->monoms[i].exps = p.monoms[i].exps;
    }

}

DistPoly::~DistPoly() {

}