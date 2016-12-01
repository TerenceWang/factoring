
#include "pollard.h"
#include "TrialDivision.h"
#include "ECM.h"

using namespace std;

mpz_class fer(mpz_class N,size_t t){
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




void printfactors(vector<mpz_class> r){
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<endl;
}


int main (void)
{
//    mpz_class a, b, c;
    mpz_class number;
    mpz_class max=2;
    max=2;
    while(cin>>number)
    {
        int size=mpz_sizeinbase(number.get_mpz_t(),2);
        if(size>100){
            cout<<"fail"<<endl;
            cout<<endl;
            continue;
        }
        vector<mpz_class> result;
        bool fail=false;
        pollard * pollard1=new pollard();
        //pollard1->dopollardp_1(&result,&fail,number);
        //pollard1->dopollardrho_brent(&result,&fail,number);

        TrialDivision * trialDivision=new TrialDivision();
        //trialDivision->doTrialDivision_Random(&result,&fail,number);
        //trialDivision->doTrialDivision_Basic(&result,&fail,number);

        ECM* ecm1 = new ECM();
        ecm1->doECM(&result,&fail,number);


        if(!fail) {
            printfactors(result);
        }
        else{
            cout<<"fail"<<endl;
        }
        cout<<endl;
    }

    return 0;
}
