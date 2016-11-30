//
// Created by Terence on 11/27/16.
//
#include <gmpxx.h>
#include <iostream>
#include <vector>
#include <stack>
#ifndef FACTORING_FERMET_H
#define FACTORING_FERMET_H

using namespace std;
class Fermet {
    public:
        Fermet();
        void doFermet(vector<mpz_class> *result, bool *fail,mpz_class N);
};


#endif //FACTORING_FERMET_H
