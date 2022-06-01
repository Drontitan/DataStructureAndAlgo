#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int gcd(int a,int b){
    if(a%b==0)return b;
    gcd(b,a%b);
}

int main(){
    cout<<gcd(12,18);
    return 0;
}