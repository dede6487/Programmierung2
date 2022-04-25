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
        if (added == false) { //if no exponents were matching, we will create a new monomial and add it to the polynomial

            if (this->m == this->am) {
                this->resize(2, this->m);
            }

            for (int i = 0; i < m; i++) {
                //if (this->monoms[i].exps[j] == exps[j]) {
                //        for (int k = i; k < m; k++) {//copys every other monom until the inserted monom,then inserts the new monom, then breaks
                //            this->monoms[k] = this->monoms[k];
                //        }
                //        this->monoms[m + 1].coeff = coeff; //potential puffer overflow, this is handeled by the if directly under the added == flase check, seems as ifthe VS code checker doesn't compute this right
                //        this->monoms[m + 1].exps = exps;
                //        this->am++;
                //        j--;
                //        break;
                //    i--;
                //}//wtf!!!!!!!!!!!
                else if (this->monoms[i].exps[j] < exps[j]) {
                    this->monoms[i].coeff = coeff;
                    this->monoms[i].exps = exps;
                    this->am++;
                    for (int k = i + 1; k <= m; k++) {//copys every other monom after the inserted monom, then breaks
                        this->monoms[k] = this->monoms[k];
                    }
                    break;
                }
            }

        }
    }


    return *this;
}

DistPoly& DistPoly::add(DistPoly& p) {

    return *this;
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
    this->m = 2;
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
    this->monoms = new Monom[(p.m)+1];
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

//constructor for struct, change struct to class, problem is because it tries to delete a pointer, that has already been deleted
DistPoly::~DistPoly() {
    //for (int i = 0; i < this->m; i++) {
    //    delete[] this->monoms[i].exps;
    //}
    //delete[] this->monoms;
}

//*****************************************************************************

void DistPoly::resize(int factor, int m) {
    Monom* NewMonoms = new Monom[factor * m];
    for (int i = 0; i < m; i++) {
        NewMonoms[i] = this->monoms[i];
    }
    delete[] this->monoms;
    this->monoms = NewMonoms;
}