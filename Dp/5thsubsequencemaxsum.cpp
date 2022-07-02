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
    int pick = vec[n]+maxsubsum(vec,n-2);// here n-2 because no adjacent element could be pick 
    int notpick = maxsubsum(vec,n-1);

    return dp[n]=max(pick,notpick);
}

// itrativesolution
int maxsubsumiterative(vector<int>vec,int n,vector<int>dp){
    dp[0]=vec[0];
   for(int i=1; i<n;i++){
       int pick = vec[i];
       if(i>1)pick+=dp[i-2];
       int notpick =dp[i-1];
       dp[i]=min(pick,notpick);
   }
   return dp[n-1];
}
// spave optimization
int maxsubssumspace(vector<int>vec){
    int n=vec.size();
    int prev=vec[0];
    int prev2=0;
   for(int i=1; i<n;i++){
     int take= vec[i];
     if(i>1)take+=prev2;
     int notake =0+prev;
     int curr= max(take,notake);
     prev2=prev;
     prev=curr;
   }
   return prev;
}

int main(){
    vector<int>vec={1,3,4,5,6,7};
    vector<int>dp(6,-1);
    cout<<maxsubssumspace(vec);
    return 0;
}