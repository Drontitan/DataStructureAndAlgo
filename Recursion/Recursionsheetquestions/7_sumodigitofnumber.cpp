#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int sumofffdigits(int n,int sum){

    int rem=n%10;
    if(rem<=0){
        return sum;
    }
    return sumofffdigits(n / 10, sum + rem);
}

int main(){
    ll n;
    cin>>n;
    cout<<sumofffdigits(n,0);
     return 0;
}