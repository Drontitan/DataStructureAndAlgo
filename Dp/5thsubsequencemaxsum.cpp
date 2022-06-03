#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recursion
int maxsubsum(vector<int>vec,int n){
    if(n==0)return vec[n];
    if(n<0)return 0;

    int pick = vec[n]+maxsubsum(vec,n-2);
    int notpick = maxsubsum(vec,n-1);

    return max(pick,notpick);
}

//memoization code
int maxsubsummemo(vector<int>vec,int n,vector<int>dp){
    if(n==0)return vec[n];
    if(n<0)return 0;
     if(dp[n]!=-1)return dp[n];
    int pick = vec[n]+maxsubsum(vec,n-2);
    int notpick = maxsubsum(vec,n-1);

    return dp[n]=max(pick,notpick);
}

// itrativesolution
int maxsubsumiterative(vector<int>vec,int n,vector<int>dp){
    dp[0]=vec[0];
    int neg=0;
   for(int i=0; i<n;i++){
       int pick = vec[i]+(i>1)?dp[i-2]:0;
       int notpick =dp[i-1];
       dp[i]=min(pick,notpick);
   }
   return dp[n-1];
}


int main(){
    vector<int>vec={1,3,4,5,6,7};
    vector<int>dp(6,-1);
    cout<<maxsubsumiterative(vec, 6,dp);
    return 0;
}