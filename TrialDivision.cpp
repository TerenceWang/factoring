//
// Created by Terence on 11/27/16.
//

#include "TrialDivision.h"

using namespace std;
TrialDivision::TrialDivision(){

}

void TrialDivision::doTrialDivision(vector <mpz_class> *result, bool *fail, mpz_class N) {
    stack<mpz_class> tempnumbers;
    tempnumbers.push(N);
    int timecnt = 0;

    while(!tempnumbers.empty() && timecnt < 200){
        mpz_class top = tempnumbers.top();
        tempnumbers.pop();
        if (mpz_probab_prime_p(top.get_mpz_t(),10))
        {
            result[0].push_back(top);
            continue;
        }
        mpz_class pf = (mpz_class)1;
        gmp_randclass r(gmp_randinit_default);
        r.seed(time(NULL));
        int cnt = 0;
        while (pf == 1 && cnt < 370000)
        {
            mpz_class temp = r.get_z_range(sqrt(top)) + 1;
            pf = gcd(top, temp);
            cnt++;
            //cout << pf << " " << temp << endl;
        }
        //cout << "!!!!" << endl;
        tempnumbers.push(pf);
        tempnumbers.push(top / pf);

        timecnt++;
        if (cnt == 370000)
            timecnt = 200;
    }
    if (timecnt == 200)
        fail[0]=true;
}