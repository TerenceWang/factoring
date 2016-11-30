
#include "pollard.h"
#include "TrialDivision.h"
#include "Fermet.h"
using namespace std;





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
        pollard1->dopollardp_1(&result,&fail,number);
//
//        TrialDivision * trialDivision=new TrialDivision();
//        trialDivision->doTrialDivision(&result,&fail,number);
//        Fermet *fermet=new Fermet();
//        fermet->doFermet(&result,&fail,number);

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
