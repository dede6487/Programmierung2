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
                if (this->monoms[j].coeff + coeff == 0) {
                    for (int l = j; l < this->am+1; l++) { //shifts the monoms into the empty element
                        this->monoms[l] = this->monoms[l + 1];
                    }
                    this->am--;
                }
                else {
                    this->monoms[j].coeff += coeff;
                }
                break;
            }
            else if (k == -1) {

                if (this->m == this->am+1) {
                    this->resize(2);
                }

                for (int l = this->am + 1; l > j; l--) {
                    this->monoms[l] = this->monoms[l-1];
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
    for (int i = 0; i < this->n; i++) {
        if (this->vars[i] != p.vars[i]) {
            cout << "Error: the variables of two added polynomials do not match";
            exit(1);
        }
    }
    if (p.am != 0) {
        //here the polynomials should be added using the previuously defined add function
    }

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

void DistPoly::println() {
    if (n == 0 || m==0 || am==0) {
        cout << "0" << endl;
    }
    else {
        for (int i = 0; i < m; i++) {
            if (this->monoms[i].coeff != 0) {
                cout << this->monoms[i].coeff;

                for (int j = 0; j < n; j++) {
                    if (this->monoms[i].exps[j] == 1) {
                        cout << this->vars[j];
                    }
                    else if (this->monoms[i].exps[j] != 0) {
                        cout << this->vars[j];
                        cout << "^" << this->monoms[i].exps[j];
                    }
                }
                if (i < am && this->monoms[i+1].coeff > 0) {
                    cout << "+";
                }
            }
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
    this->monoms = new Monom[this->m];
    //check if monomial is null, e.g. is actually a monomial, this check should be included everywhere, where such copying actions are performed
    for (int i = 0; i < m; i++) {
        this->monoms[i].coeff = p.monoms[i].coeff;
        for (int j = 0; j < p.n; j++) {
            this->monoms[i].exps[j] = p.monoms[i].exps[j];
        }
    }

}

DistPoly& DistPoly::operator=(DistPoly& p) {
    this->n = p.n;
    this->vars = p.vars;
    this->m = p.m;
    this->am = p.am;
    this->monoms = new Monom[this->m];
    for (int i = 0; i < m; i++) {
        this->monoms[i].coeff = p.monoms[i].coeff;
        for (int j = 0; j < p.n; j++) {
            this->monoms[i].exps[j] = p.monoms[i].exps[j];
        }
    }

    return *this;
}

//problem is because it tries to delete a pointer, that has already been deleted -> better: create constructor and destructor for class Monom
DistPoly::~DistPoly() {
    //for (int i = 0; i < this->m; i++) {
    //    delete[] this->monoms[i].exps;
    //}
    delete[] this->monoms;
}

void DistPoly::resize(int factor) {
    if (factor > 0) {
        Monom* NewMonoms = new Monom[factor * this->m];
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
    else{
        cout << "Error: factor must be greater than 0";
    }
}
//idea: create new array of monoms with emty constructor, then initialize them by assigning a newly constructed monom (with different constructor) to every element of the array


//constructor
//Monom::Monom(int coeff, int* exps, int n) {
//    this->coeff = coeff;
//    this->exps = new int[n]; //creates a new array of exponents, this is in order to have seperate pointers and deallocate their respectivve memory later (for DistPoly)
//    this->exps = exps;
//}
//
//
////constructor
//Monom::Monom() {
//    this->coeff = 0;
//    this->exps = 0;
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

//destructor
//Monom::~Monom() {
//    delete[] exps;
//}
