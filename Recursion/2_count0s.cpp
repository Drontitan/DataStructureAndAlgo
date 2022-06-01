#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int helper(int n,int c){
    if(n==0){
       return c;
    }
    int rem=n%10;
    if(rem==0){
        return helper(n / 10, c + 1);
    }
    return helper(n/10,c);
    
}
int countzeros(int n){
   return helper(n,0);
}
int main(){
    ll n;
    cin>>n;
    cout<<countzeros(n);
    
    return 0;
}