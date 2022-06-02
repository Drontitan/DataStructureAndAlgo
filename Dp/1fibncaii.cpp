#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// memoization approach   top to botoom approach 
// int f(int n,vector<int>&dp){
//     if(n<=1)return n;

//     if(dp[n]!=-1)return dp[n];

//     return dp[n]=f(n-1,dp)+f(n-2,dp);
// }

// iterative approach using the tabular form  bottom to up 
// ** time and space complex O(n) O(n)+O(n);
// int f(int n, vector<int>&dp){
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];

// }
// ** reducin the space complexity  O(N)+O(N)
int f(int n, vector<int>&dp){
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++){
        int curr = prev2+prev;
        prev2=prev;
        prev=curr;
    }
    return prev;

}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<f(n,dp);
    return 0;
}