#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sumofthedigits(int n){

    if(n%10==n){
        return n;
    }
      return (sumofthedigits(n/10)*(n%10));
}
 int main()
{
    int n;
    cin>>n;
   int a= sumofthedigits(n);
   cout<<a;
    return 0;
}