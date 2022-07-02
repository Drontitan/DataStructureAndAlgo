#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recusrion 
int subsetsum(vector<int>vec,int i,int sum){

   if(i==0){
       if(sum==0 && vec[0]==0)return 2;
       if(sum==0 || sum==vec[0])return 1;
       return 0;
   }
   int  nottake = subsetsum(vec,i-1,sum);
    int take= 0;
   if(vec[i]<=sum){
       take = subsetsum(vec,i-1,sum-vec[i]);
   }
     return take+nottake;

}


// memoization 
int subsetsummemo(vector<int>vec,int i,int sum,vector<vector<int>>&dp){
    
  if(i==0){
       if(sum==0 && vec[0]==0)return 2;
       if(sum==0 || sum==vec[0])return 1;
       return 0;
   }
   if(dp[i][sum]!=-1)return dp[i][sum];
   int  nottake= subsetsummemo(vec,i-1,sum,dp);
   int take= 0;
   if(vec[i]<=sum){
       take= subsetsummemo(vec,i-1,sum-vec[i],dp);
   }
     return  dp[i][sum]=take+ nottake;
}

// tabulation solution
int subsetsumiterative(vector<int>vec,int n,int sum,vector<vector<int>>&dp){
    if(vec[0]==0)dp[0][0]=2;
     else dp[0][1]=1;
   for(int i= 0; i<n;i++)dp[i][0]=1;
   if( vec[0]!=0 && vec[0]<=sum)dp[0][vec[0]]=1;
    for(int i=1;i<n;i++){
        for(int s=0;s<=sum;s++){
              int  nottake=dp[i-1][s];
   int take= 0;
   if(vec[i]<=s){take= dp[i-1][sum-vec[i]];}
    dp[i][s]=nottake+take;
        }
    }
    return dp[n-1][sum];
}



int main(){
    vector<int>vec={1,2,3,4};
    long long sum=0;
    for(auto &it :vec)sum+=it;
    int diff=2;
    if((sum-diff)<0 || (sum-diff)%2)return false;
    int n=vec.size();
    int m= (sum-diff)/2;
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    vector<vector<int>>dpit(n,vector<int>(m+1,0));
     cout<<subsetsum(vec,n-1,m)<<endl;
     cout<<subsetsummemo(vec,n-1,m,dp)<<endl;
     cout<<subsetsumiterative(vec,n,m,dpit)<<endl;
 
    return 0;
}