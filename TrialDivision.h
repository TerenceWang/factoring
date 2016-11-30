//
// Created by Terence on 11/27/16.
//
#include <gmpxx.h>
#include <iostream>
#include <vector>
#include <stack>

#ifndef FACTORING_TRIALDIVISION_H
#define FACTORING_TRIALDIVISION_H

using namespace std;

class TrialDivision {
    public:
        TrialDivision();
        void doTrialDivision(vector<mpz_class> *result, bool *fail,mpz_class N);
};


#endif //FACTORING_TRIALDIVISION_H
