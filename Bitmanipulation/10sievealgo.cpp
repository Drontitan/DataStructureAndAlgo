#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e7+10;
vector<bool>isprime(N,1);
vector<int>hp(N,0),lp(N,0);
int main(){

    // sieve algorithm 
    isprime[0]=isprime[1]=false;
    // for (int i = 2; i <N; ++i)
    // {
    //     if(isprime[i]==true){
    //         for (int j= 2*i; j<N; j+=i)
    //         {
    //            isprime[j]=false;
    //         }
            
    //     }                   
    // }         
    for (int i = 2; i <N; ++i)
    {
        if(isprime[i]==true){
            lp[i]=hp[i]=i;//prime number ka lowest aur highest vo khud hai na
            for (int j= 2*i; j<N; j+=i)
            {
               isprime[j]=false;
               hp[j]=i;
               if(lp[j]==0){
                   lp[j]=i;
               }
            }
            
        }                   
    }         
    for (int i = 1; i < 100; ++i)
    {
        cout<<lp[i]<<"  "<<hp[i]<<endl;
    }
    
    //1st variation highest prime and lowest prim in the number

    // int q;
    // cin>>q;
    // while(q--){
    //     int num;
    //     cin>>num;
    //     if(isprime[num])cout<<"prime\n";
    //     else cout<<"Not a prime\n";
    // }
    return 0;
}