#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())


int LCS(string x,string y,int n,int m){

     if(n==0||m==0){
         return 0;
     }
     if(x[n-1]==y[m-1]){
         return 1+LCS(x,y,n-1,m-1);
     }
     else{
         return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
     }
     
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<LCS(x,y,n,m);
    return 0;
}