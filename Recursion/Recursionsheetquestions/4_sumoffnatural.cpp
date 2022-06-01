#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sumofnaturlanum(int n){
    if(n<=0){
        return 0;
    }
    return (n + sumofnaturlanum(n-1));
}
int main(){
    int n;
    cin>>n;
    cout <<sumofnaturlanum(n);
     return 0;
}