#include"RecPoly.h"


// polynomial with n>=0 coefficients and given variable name
RecPoly::RecPoly(string var, int n, Ring** coeffs) {
	this->var = var;
	this->n = n;
	this->coeff = new Ring*[n];
	for (int i = 0; i < n; i++) {
		coeff[i] = coeffs[i]->clone();
	}
}

// copy constructor, copy assignment operator, destructor
RecPoly::RecPoly(RecPoly& p) {
	this->var = p.var;
	this->n = p.n;
	
	//for (int i = 0; i < this->n; i++) {
	//	delete coeff[i];
	//}
	//delete[] coeff;

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
RecPoly* RecPoly::clone() {
	RecPoly* c = new RecPoly(*this);

	return c;
}

// the string representation of this element
string RecPoly::str() {
	string str = "";
	if (n == 0) {
		str = "0" ;
	}
	else {
		for (int i = 0; i < n; i++) {
			str += coeff[i]->str() + "*" + var + "^" + to_string(i);
		}
	}

	return str;
}

// the constant of the type of this element and the inverse of this element
RecPoly* RecPoly::zero() {
	return &RecPoly(this->var, 0, {});
}

RecPoly* RecPoly::operator-() {

}

// sum and product of this element and c
RecPoly* RecPoly::operator+(Ring* c) {

}

RecPoly* RecPoly::operator*(Ring* c) {

}

// comparison function
bool RecPoly::operator==(Ring* c) {

}