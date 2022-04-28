//for (int i = 0, j = 0; i < m; i++) {
//    if (this->monoms[i].exps[j] > exps[j]) {
//        this->monoms[i] = this->monoms[i];
//    }
//    else if (this->monoms[i].exps[j] == exps[j]) {
//        if (j == n - 1) {
//            for (int k = i; k < m; k++) {//copys every other monom until the inserted monom,ten inserts the new monom, then breaks
//                this->monoms[k] = this->monoms[k];
//            }
//            this->monoms[m + 1].coeff = coeff; //potential puffer overflow, this is handeled by the if directly under the added == flase check, seems as ifthe VS code checker doesn't compute this right
//            this->monoms[m + 1].exps = exps;
//            this->am++;
//            break;
//        }
//        j++;
//        i--;
//    }
//    else if (this->monoms[i].exps[j] < exps[j]) {
//        this->monoms[i].coeff = coeff;
//        this->monoms[i].exps = exps;
//        this->am++;
//        for (int k = i + 1; k <= m; k++) {//copys every other monom after the inserted monom, then breaks
//            this->monoms[k] = this->monoms[k];
//        }
//        break;
//    }
//}


//for (int i = 0; i < m; i++) {
//    //if (this->monoms[i].exps[j] == exps[j]) {
//    //        for (int k = i; k < m; k++) {//copys every other monom until the inserted monom,then inserts the new monom, then breaks
//    //            this->monoms[k] = this->monoms[k];
//    //        }
//    //        this->monoms[m + 1].coeff = coeff; //potential puffer overflow, this is handeled by the if directly under the added == flase check, seems as ifthe VS code checker doesn't compute this right
//    //        this->monoms[m + 1].exps = exps;
//    //        this->am++;
//    //        j--;
//    //        break;
//    //    i--;
//    //}//wtf!!!!!!!!!!!
//    //else
//    if (this->monoms[i].exps[j] < exps[j]) {
//        this->monoms[i].coeff = coeff;
//        this->monoms[i].exps = exps;
//        this->am++;
//        for (int k = i + 1; k <= m; k++) {//copys every other monom after the inserted monom, then breaks
//            this->monoms[k] = this->monoms[k];
//        }
//        break;
//    }
//}

//bool added = false;
//for (int j = 0; j < this->m; j++) { //steps through every single monomial that is already existing in this polynomial
//    int same = 0;
//    for (int i = 0; i < this->n; i++) { //checks every exponent of a polynomial if it is equivalent to the given one, if not same will increase by one
//        if (this->monoms[j].exps[i] != exps[i]) {
//            same++;
//        }
//    }
//    if (same == 0) { //if same wasn't increased, the monomial has the same exponents, the coefficients can thus be added together and the for will break
//        this->monoms[j].coeff += coeff;
//        added = true;
//        break;
//    }
//}
////adding above works
////adding below requires rework
//if (added == false) { //if no exponents were matching, we will create a new monomial and add it to the polynomial
//
//    if (this->m == this->am) {
//        this->resize(2);
//    }
//
//    int y = this->sort(exps, this->n);
//
//    for (int i = y; i <= this->am; i++) {
//        this->monoms[i + 1].coeff = this->monoms[i].coeff;
//        this->monoms[i + 1].exps = this->monoms[i].exps;
//    }
//
//    this->monoms[y].coeff = coeff;
//    this->monoms[y].exps = exps;
//
//}

//using namespace std;
//
//DistPoly& DistPoly::add(DistPoly& p) {
//
//    return *this;
//}
//
//
//
//void DistPoly::println_brkts() {
//    if (n == 0) {
//        cout << "0" << endl;
//    }
//    else {
//        cout << "vars = ";
//        for (int i = 0; i < n; i++) {
//            cout << this->vars[i];
//        }
//        cout << "\n";
//        cout << "Polynomial = [";
//        for (int i = 0; i < m; i++) {
//            cout << "{";
//            cout << this->monoms[i].coeff << ", ";
//            cout << "(";
//            for (int j = 0; j < n; j++) {
//                cout << this->monoms[i].exps[j];
//                cout << " ,";
//            }
//            cout << ")";
//            cout << "}, ";
//        }
//        cout << "]" << endl;
//    }
//}
//
////constructor for Monom, problem is because it tries to delete a pointer, that has already been deleted
//
//
//constructor
//Monom::Monom(int coeff, int* exps, int n) {
//    this->coeff = coeff;
//    this->exps = new int[n]; //creates a new array of exponents, this is in order to have seperate pointers and deallocate their respectivve memory later (for DistPoly)
//    this->exps = exps;
//}

//constructor
//Monom::Monom() {
//    this->coeff = 0;
//    this->n = 1;
//    this->exps = 0;//new int[n];
//    //for (int i = 0; i < n; i++) {
//    //    this->exps[i] = 0;
//    //}
//
//}

//Monom::Monom(int coeff, int* exps) {
//    this->coeff = coeff;
//    this->exps = new int[this->n];
//    for (int i = 0; i < n; i++) {
//        this->exps[i] = exps[i];
//    }
//}

//copy assignment operator
//Monom& Monom::operator=(Monom& m) {
//    this->coeff = m.coeff;
//    this->exps = new int[m.n];
//    for (int i = 0; i < m.n; i++) {
//        this->exps[i] = m.exps[i];
//    }
//
//    return *this;
//}