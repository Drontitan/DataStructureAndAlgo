#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void pattern(int r,int c){
    if(r==0){
        return;
    }
   if(c<r){
       cout<<"*";
       pattern(r,c+1);
   }
   else{
       cout<<"\n";
       pattern(r-1,0);
   }
}
int main(){
    ll n;
    // cin>>n;
    pattern(4,0);
    return 0;
}