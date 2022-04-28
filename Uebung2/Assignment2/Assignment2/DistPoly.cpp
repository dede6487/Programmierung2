//******************************************************************
// "DistPoly.cpp"
// 
// is the cpp file, where the member-functions of the DistPoly Class
// are defined.
// 
// created by Felix Dresser, 28.04.2022
//******************************************************************

#include"DistPoly.h"
#include<iostream>

using namespace std;

//******************************************************************
// class "Monom"
// 
// The Monom class is a private class of the DistPoly class and
// serves as a structure for saving monomials in the DistPoly class.
// 
// coeff ... is the coefficient of a monomial
// exps ... is an array of integers, that holds the exponents of the monomial
// n ... is the number of variables in a monomial
// 
// member functions ... more description in the comments above them
//******************************************************************

class DistPoly::Monom
{
public:
    int coeff;
    int* exps;
    int n;

    //constructors
    Monom();
    Monom(int coeff, int* exps, int n); 

    //copy constructor, copy assignment operator, destructor
    Monom& operator=(Monom& m);

    //destructor
    ~Monom();
};

//******************************************************************
// Method "add(itn coeff, int* exps)"
// 
// is a member function of the class "DistPoly" and adds the monomial
// given by its coefficient and its exponent to the current polynomial
// 
// coeff ... ceofficient of the monomial that will be added
// exps ... exponents of the monomial that will be added
//******************************************************************

DistPoly& DistPoly::add(int coeff, int* exps) {
    if (coeff !=0) {
        for (int j = 0; j <= this->m; j++) {
            int k = 1;
            //checks where to insert/add the polynomial
            if (j < this->m) {
                k = sort(exps, this->n, j);
            }
            if (k == 0) {
                if (this->monoms[j].coeff + coeff == 0) {
                    for (int l = j; l < this->am+1; l++) { //shifts the monoms into the gap to fill it
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

                if (this->m >= this->am+1) {
                    this->resize(2);
                }

                for (int l = this->am+1; l > j; l--) {
                    this->monoms[l] = this->monoms[l-1];
                }
                this->monoms[j].coeff = coeff;
                delete[] this->monoms[j].exps;
                this->monoms[j].exps = new int[this->n];
                for (int i = 0; i <this->n; i++)
                {
                    this->monoms[j].exps[i] = exps[i];
                }
                this->am++;
                break;
            }
        }
    }

    return *this;
}

//******************************************************************
// Method "add(DistPoly& p)"
// 
// is a member function of the class "DistPoly" and adds one 
// polynomial to the polynomial.
// 
// p ... polynomial that should be added
//******************************************************************

DistPoly& DistPoly::add(DistPoly& p) {
    if (this->n != p.n) {
        cout << "Error: the number of variables of two added polynomials is different";
        exit(2);
    }
    for (int i = 0; i < this->n; i++) {
        if (this->vars[i] != p.vars[i]) {
            cout << "Error: the variables of two added polynomials do not match";
            exit(1);
        }
    }
    if (p.am != 0) {
        for (int i = 0; i <= p.am; i++){
            this->add(p.monoms[i].coeff, p.monoms[i].exps);
        }
    }
    return *this;
}

//******************************************************************
// Method "sort"
// 
// is a private member function of DistPoly used in the add method to determine
// the correct place in which the new monomial should be added.
// 
// It takes the exponents of a monomial and gives back 
// 
// -> 0 if the given exponents match the exponents of this polynomial.
// -> 1 if the given exponents need to be inserted after this polynomial.
// -> -1 if the given exponents need to be inserted before this polynomial.
// 
// exps ... exponents to be sorted in
// n ... number of variables in this polynomial
// j ... the number of the monomial it should check against in the 
// monomial array of the polynomial
//******************************************************************

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

//******************************************************************
// Method "println()"
// 
// is a member function of the "DistPoly" class.
// it prints out the given polynomial.
//******************************************************************

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

//******************************************************************
// constructor "DistPoly(int n, string* vars)"
// 
// constructs and initializes Polynomials
//******************************************************************

DistPoly::DistPoly(int n, string* vars) {
    this->n = n;
    this->vars = new string[n];
    for (int i = 0; i < n; i++) {
        this->vars[i] = vars[i];
    }
    this->m = 1;
    this->am = 0;
    this->monoms = new Monom[m];
    for (int j = 0; j < m; j++) {
        this->monoms[j] = *new Monom(0, new int[n] {0}, n);
    }
}

//******************************************************************
// copy constructor "DistPoly(DistPoly& p)"
// 
// copy constructor for "DistPoly"
//******************************************************************

DistPoly::DistPoly(DistPoly& p) {
    this->n = p.n;
    delete[] this->vars;
    this->vars = new string[n];
    for (int i = 0; i < n; i++) {
        this->vars[i] = p.vars[i];
    }
    this->m = p.m;
    this->am = p.am;
    delete[] this->monoms;
    this->monoms = new Monom[this->m];
    for (int i = 0; i < m; i++) {
        this->monoms[i] = *new Monom(p.monoms[i].coeff, p.monoms[i].exps, p.n);
    }
}

//******************************************************************
// copy assignment operator "DistPoly::operator=(DistPoly& p)"
// 
//  copy assignment operator for "DistPoly"
//******************************************************************

DistPoly& DistPoly::operator=(DistPoly& p) {
    this->n = p.n;
    delete[] vars;
    this->vars = new string[n];
    for (int i = 0; i < n; i++) {
        this->vars[i] = p.vars[i];
    }
    this->m = p.m;
    this->am = p.am;
    delete[] monoms;
    this->monoms = new Monom[this->m];
    for (int i = 0; i < m; i++) {
        this->monoms[i] = *new Monom(p.monoms[i].coeff, p.monoms[i].exps, p.n);
    }

    return *this;
}

//******************************************************************
// destructor "~DistPoly()"
// 
// destructor for "DistPoly" 
//******************************************************************

DistPoly::~DistPoly() {
        delete[] this->vars;
        delete[] this->monoms;
}

//******************************************************************
// Method "resize(int factor)"
// 
// is a member function of "DistPoly".
// It enlarges the size of the array by a given factor (>1) of polynomials 
// and copys the old polynomial into it.
// 
// factor ... the factor by which the polynomial should be enlarged
//******************************************************************

void DistPoly::resize(int factor) {
    if (factor > 1) {
        Monom* newMonoms = new Monom[(factor * this->m) + 1];
        for (int i = 0; i < this->am+1; i++) {
            newMonoms[i] = this->monoms[i];
        }
        delete[] this->monoms;
        this->monoms = newMonoms;
        this->m = factor * (this->m) + 1;
    }
    else{
        cout << "Error: factor must be greater than 0";
    }
}

//******************************************************************
// constructor "Monom(int coeff, int* exps, int n)"
// 
// is a constructor for the private member class of "DistPoly"
// called "Monom".
// It constructs a monomial with the values of:
// 
// coeff ... is the coefficient of the monomial
// exps ... is the exponent array
// n ... is the number of variables 
//******************************************************************

DistPoly::Monom::Monom(int coeff, int* exps, int n) {
    this->n = n;
    this->coeff = coeff;
    this->exps = new int[n]; //creates a new array of exponents, this is in order to have seperate pointers and deallocate their respectivve memory later (for DistPoly)
    for (int i = 0; i < n; i++) {
        this->exps[i] = exps[i];
    }
}

//******************************************************************
// constructor "Monom()"
// 
// is the empty constructor for the private member class of "DistPoly"
// called "Monom". 
//******************************************************************

DistPoly::Monom::Monom() {
    this->n = 1;
    this->coeff = 0;
    this->exps = new int[n];
    for (int i = 0; i < this->n; i++) {
        this->exps[i] = 0;
    }
}

//******************************************************************
// copy assignment operator "Monom::operator=(Monom& m)"
// 
// is the copy assignment operator for the private member class of "DistPoly"
// called "Monom".
//******************************************************************

DistPoly::Monom& DistPoly::Monom::operator=(Monom& m) {
    this->n = m.n;
    this->coeff = m.coeff;
    delete[] exps;
    this->exps = new int[n]; //creates a new array of exponents, this is in order to have seperate pointers and deallocate their respectivve memory later (for DistPoly)
    for (int i = 0; i < n; i++) {
        this->exps[i] = m.exps[i];
    }
    return *this;
}

//******************************************************************
// destructor "~Monom()"
// 
// is the destructor for the private member class of "DistPoly"
// called "Monom".
//******************************************************************

DistPoly::Monom::~Monom() {
    delete[] exps;
}