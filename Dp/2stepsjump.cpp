#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// you are given the nth stair you are starting from the 0th stair and you can climb 1 or 2 stairs
// return number of ways to reach the nth stair 

int jump(int n){

   if(n==0)return 1;
   if(n==1)return 1;  // its for the index-2 
   int left= jump(n-1);
   int right= jump(n-2);
   return left+right;
}


// memozation
int jumpmemo(int n,vector<int>&dp){
    
   if(n==0)return 1;
   if(n==1)return 1;  // its for the index-2 
   if(dp[n]!=-1)return dp[n];
   int left= jump(n-1);
   int right= jump(n-2);
   return   dp[n]= left+right;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
   cout<<jump(n)<<endl;;
   cout<<jumpmemo(n,dp);
    return 0;
}