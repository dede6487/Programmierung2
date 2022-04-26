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