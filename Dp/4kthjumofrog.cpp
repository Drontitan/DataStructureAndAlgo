#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int kthjump(vector<int>vec,int n,int k){
    if(n==0)return 0;
    int minsteps=1e9;
    for (int j =1; j<=k;j++){
        if(n-j>0){
       int jumps= kthjump(vec,n-j,k)+abs(vec[n]-vec[n-j]);
        minsteps=min(jumps,minsteps);
        }
    }
    return minsteps;
}
//  memoization code 
int kthjumpmemo(vector<int>vec,int n,int k,vector<int>dp){
    dp[0]=0;
    int minsteps=INT_MAX;
    for (int j =1; j<=k;j++){
        if(n-j>0){
          if(dp[n]!=-1)return dp[n];
         int jumps= kthjump(vec,n-j,k)+abs(vec[n]-vec[n-j]);
        dp[n]=min(jumps,minsteps);
        }
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n,-1);
     vector<int>vec={7,4,4,2,6,6,3,4};
     int k=3;
     cout<<kthjump(vec,n,k);
    //  cout<<kthjumpmemo(vec,n-1,k,dp);
    return 0;
}