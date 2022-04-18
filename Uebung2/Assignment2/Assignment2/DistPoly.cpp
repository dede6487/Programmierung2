#include"DistPoly.h"
#include<iostream>

using namespace std;

DistPoly& DistPoly::add(int coeff, int* exps) {

    //falls die polynome gleiche exponenten haben oder das erste das nullpolynom ist, können sie addiert werden
    //if (this->n = 0) {
    //    this->coeff = coeff;
    //    this->exps = exps;
    //}
    //else {
        for (int i = 0; i <= n; i++) {
            if (this->exps[i] != exps[i]) {

                //soll zukünftig ein um ein polynom größeres array an polynomen erstellen
                //funktioniert zurzeit (vielleicht) nur mit länge 1
                DistPoly p(this->n, this->vars);
                p.coeff = coeff;
                p.exps = exps;

                DistPoly q[2] = { *this, p };

                //q stimmt mit DistPoly& nicht zusammen, muss der selbe typ sein

                break;
            }
            else if (n == i) {
                this->coeff += coeff;
            }
        //}
    }

    return *this;
}

DistPoly& DistPoly::add(DistPoly& p) {

    return *this;
}

void DistPoly::println() {
    cout << "n = " << this->n << endl;
    for (int i = 0; i < n; i++) {
        cout << "vars = " << this->vars[i] << endl;
    }
    cout << "coeff = " << this->coeff << endl;
    for (int i = 0; i < n; i++) {
        cout << "exps = " << this->exps[i] << endl;
    }
}

DistPoly::DistPoly(int n, string* vars) {
    this->n = n;
    this->vars = vars;
    this->coeff = 0;
    this->exps = new int[n];
       for (int i = 0; i < n; i++) {
            this->exps[i] = 0;
       }
}

DistPoly::DistPoly(DistPoly& p) {
    this->n = p.n;
    this->vars = p.vars;
    this->coeff = p.coeff;
    this->exps = p.exps;
}

DistPoly::~DistPoly() {
   //delete[] exps;
   // delete[] vars;
}