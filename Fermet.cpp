//
// Created by Terence on 11/27/16.
//

#include "Fermet.h"

using namespace std;

Fermet::Fermet() {

}
mpz_class fer(mpz_class N){
    mpz_class x=sqrt(N);
    mpz_class tt=x*x-N;
    int count=0;
    while (!mpz_perfect_square_p(tt.get_mpz_t())){
        count++;
        x++;
        tt=x*x-N;
        if(count>100000)
            return -1;
    }
    mpz_class y=sqrt(tt);
    return x+y;
}

void Fermet::doFermet(vector <mpz_class> *result, bool *fail, mpz_class N) {
    stack<mpz_class>  stacks;
    stacks.push(N);
    fail[0]=false;
    while(!stacks.empty()){
        mpz_class temp=stacks.top();
        stacks.pop();
        if(mpz_probab_prime_p(temp.get_mpz_t(),10)&&temp>1){
            result[0].push_back(temp);
            continue;
        }
        if (temp%2==0){
            mpz_class two=2;
            stacks.push(two);
            stacks.push(temp / 2);
        }else {
            mpz_class s = fer(temp);
            if(s<0) {
                fail[0] = true;
                continue;
            }
            stacks.push(s);
            stacks.push(temp / s);
        }
    }
}
