#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int jump(int n){
    
   if(n==0)return 1;
   if(n==1)return 1;
  int left= jump(n-1);
   int right= jump(n-2);
   return left+right;
}

int main(){
    int n;
    cin>>n;
   cout<<jump(n);
    return 0;
}