#include"DistPoly.h"
#include<iostream>

using namespace std;

DistPoly& DistPoly::add(int coeff, int* exps) {

    for (int i = 0; i <= n; i++) {
        if (this->exps[i] == exps[i]) {
            this->coeff = coeff;
        }
    }

    return *this;
}

DistPoly& DistPoly::add(DistPoly& p) {

    return *this;
}

void DistPoly::println() {
    cout << "[" << "n = " << n << endl;
    cout << "[" << "vars = " << vars[1] << endl;
    cout << "[" << "coeff = " << coeff << endl;
    cout << "[" << "exps = " << exps[1] << endl;
}

DistPoly::DistPoly(int n, string* vars) {
    this->n = n;
    this->vars = vars;
    this->coeff = 0;
    for (int i = 0; i <= n; i++) {
        this->exps[n] = 0;
    }
}

DistPoly::DistPoly(DistPoly& p) {

}

DistPoly::~DistPoly() {

}