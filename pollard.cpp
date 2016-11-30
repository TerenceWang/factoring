//
// Created by Terence on 11/27/16.
//

#include "pollard.h"
#include "factoring.h"

pollard::pollard(){

}

mpz_class f(mpz_class a,mpz_class c){
    mpz_class result=0;
    result=a*a+c;
    return result;
}

mpz_class pollard::pollardrho_brent(mpz_class N){
    mpz_class x,y,c;
    mpz_class d=1;
    int tt=0;
    srand(time(NULL));
    x = N / (primelist[rand() % primelistsize]) + 2;
    c = primelist[rand() % primelistsize] % N + 2;

    y=x;
    int i=1;
    while(1){
        tt++;
        x=f(x,c) % N;
        d=gcd(abs(x-y),N);
        if(d>1 && d<N){
            return d;
        }
        if (d==N){
            c = primelist[rand() % primelistsize] % N + 2;
        }
        if (i==tt){
            y=x;
            i=i*2;
        }
        if(tt>=600000)
            break;
    }
    return -1;
}


mpz_class pollard::pollardrho(mpz_class N){

    mpz_class x,y,c;
    mpz_class d=1;
    int tt=0;
    srand(time(NULL));
    x = N / (primelist[rand() % primelistsize]) + 2;
    c = primelist[rand() % primelistsize] % N + 2;

    y=x;


    while(d==1){
        tt++;
        x=f(x,c) % N;
        y=f(f(y,c) % N,c)%N;

        if (x==y)
            return -1;
        if(tt>=330000)
            return -1;
        d=gcd(abs(x-y),N);
    }
    return d;
}

void pollard::dopollardrho(vector <mpz_class> *result, bool *fail,mpz_class N) {
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
            mpz_class s = pollardrho(temp);
            if(s<0) {
                fail[0]= true;
                break;
            }
            stacks.push(s);
            stacks.push(temp / s);
        }
    }
}

void pollard::dopollardrho_brent(vector <mpz_class> *result, bool *fail, mpz_class N){
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
            mpz_class s = pollardrho_brent(temp);
            if(s<0) {
                fail[0] = true;
                break;
            }
            stacks.push(s);
            stacks.push(temp / s);
        }
    }
}
mpz_class	LCM(mpz_class n) {
    if (n < 3)
        return (mpz_class)2;
    else
        return lcm(LCM(n-1), n);
}

mpz_class pollard::pollardp_1(mpz_class n, mpz_class a, mpz_class K){

    mpz_class d, k, t;
    int iteration = 0;

    k = LCM(K);
    for (int cnt = 0; cnt < 50000; cnt++,iteration++){
        if (gcd(a, n) > 1)
            return gcd(a, n);

        mpz_class temp;
        mpz_powm(temp.get_mpz_t(), a.get_mpz_t(), k.get_mpz_t(), n.get_mpz_t());
        t = temp % n;
        d = gcd(t-1, n);
        if ( (1<d) && (d<n) )
            return d;
        if ( (0==(K%60)) || (d==n && a+1<n ) || iteration>80){
            k = LCM(++K);
            a %= n;
            iteration = 0;
        }
        else if ( d==1 ) {
            a++;
        }
        else
            break;
    }
    return -1;
}


void pollard::dopollardp_1(vector<mpz_class> *result, bool *fail, mpz_class n){

    mpz_class pf, a, k;
    a = 2;
    k = 2;

    while(!mpz_probab_prime_p(n.get_mpz_t(),10)){
        pf = pollardp_1(n, a, k);
        if (pf == 0) {
            fail[0] = true;
            break;
        }
        result[0].push_back(pf);
        n /= pf;
    }
    result[0].push_back(n);

}
