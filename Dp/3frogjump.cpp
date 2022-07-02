#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int noofjumps(int n,vector<int>vec,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int left = noofjumps(n-1,vec,dp)+abs(vec[n]-vec[n-1]);
    int right=1e9;
    if(n>1){
        right = noofjumps(n-2,vec,dp)+abs(vec[n]-vec[n-2]);
    }
   return  dp[n]=min(left,right);
}


int tabulationnoofjumps(int n,vector<int>vec,vector<int>dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs= dp[i-1]+abs(vec[i]-vec[i-1]);
        int ss=INT_MAX;
        if(i>1){
         ss= dp[i-2]+abs(vec[i]-vec[i-2]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];

}

// space optimization 
int tabulationnoofjumpspace(int n,vector<int>vec){
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs= prev+abs(vec[i]-vec[i-1]);
        int ss=INT_MAX;
        if(i>1){
         ss= prev2+abs(vec[i]-vec[i-2]);
        }
        int curr=min(fs,ss);
        prev2=curr;
        prev=prev2;
    }
    return prev;

}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    vector<int>vec={7,4,4,2,6,6,3,4};
    // cout<<tabulationnoofjumps(n,vec,dp);
    cout<<noofjumps(n,vec,dp)<<endl;;
    cout<<tabulationnoofjumpspace(n-1,vec);
    return 0;
}