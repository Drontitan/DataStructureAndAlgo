#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(int n,int i=2){
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    return isprime(n, i + 1);
}

int main(){
    ll n;
    cin>>n;
    if (isprime(n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
        return 0;
}