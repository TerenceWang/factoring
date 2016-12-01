//
// Created by Terence on 11/27/16.
//


#include <gmpxx.h>
#include <iostream>
#include <vector>
#include <stack>

#ifndef FACTORING_POLLARD_H
#define FACTORING_POLLARD_H


using namespace std;
class pollard {
    private:
        mpz_class pollardrho(mpz_class N);
        mpz_class pollardrho_brent(mpz_class N);
        mpz_class pollardp_1(mpz_class n, mpz_class a, mpz_class K);
    public:
        pollard();
        void dopollardrho(vector<mpz_class> *result, bool *fail,mpz_class N);
        void dopollardrho_brent(vector<mpz_class> *result, bool *fail,mpz_class N);
        void dopollardp_1(vector<mpz_class> *result, bool *fail,mpz_class N);
};

mpz_class LCM(mpz_class n);

#endif //FACTORING_POLLARD_H
