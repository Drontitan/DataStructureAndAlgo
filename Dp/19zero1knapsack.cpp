#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int recursion(vector<int>weight,vector<int>vec,int i ,int capacity){
    if(i==0){
        if(weight[0]<=capacity)return vec[0];
        else return 0;
    }
    int notpick =0+recursion(weight,vec,i-1,capacity);
    int take=-1e9;
    if(weight[i]<=capacity){
        take= vec[i]+recursion(weight,vec,i-1,capacity-weight[i]);
    }
    return max(notpick,take);
}

// memoization

int recursionmemo(vector<int>&weight,vector<int>vec,int i ,int capacity,vector<vector<int>>&dp){
      if(i==0){
        if(weight[0]<=capacity)return vec[0];
        else return 0;
    }

    if(dp[i][capacity]!=-1)return dp[i][capacity];
    int notpick =0+recursionmemo(weight,vec,i-1,capacity,dp);
    int take=-1e9;
    if(weight[i]<=capacity){
        take= vec[i]+recursionmemo(weight,vec,i-1,capacity-weight[i],dp);
    }
    return dp[i][capacity]=max(notpick,take);
}
// tabulation

int recursioniterative(vector<int>&weight,vector<int>vec,int n,int capacity,vector<vector<int>>&dp){

      for(int wei =weight[0]; wei <=capacity; wei++)dp[0][wei]==vec[0];
      for(int i= 1 ;i <n;i++){
          for(int w=0; w<=capacity;w++){
                int notpick =0+dp[i-1][w];
         int take=INT_MIN;
           if(weight[i]<=w){
        take= vec[i]+dp[i-1][w-weight[i]];
        } 
           dp[i][w]=max(notpick,take);
          }
      }
   
    return dp[n-1][capacity];
}
// sapceoptimiszation
int recursioniterativespace(vector<int>&weight,vector<int>vec,int n,int capacity){
    vector<int>prev(capacity+1,0),curr(capacity+1,0);
      for(int wei =weight[0]; wei <=capacity; wei++)prev[wei]=vec[0];
      for(int i= 1 ;i <n;i++){
          for(int w=0; w<=capacity;w++){
                int notpick =0+prev[w];
         int take=-1e9;
           if(weight[i]<=w){
        take= vec[i]+prev[w-weight[i]];
        } 
           curr[w]=max(notpick,take);
          }
          prev=curr;
      }
   
    return prev[capacity];
}

int main(){
    vector<int>weight={2,6,4,5};
    vector<int>value={30,50,10,70};
    int n=value.size();
    int capacity=5;
    vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
    vector<vector<int>>dpit(n,vector<int>(capacity+1,0));
    cout<<recursion(weight,value,n-1,capacity)<<endl;
    cout<<recursionmemo(weight,value,n-1,capacity,dp)<<endl;;
    cout<<recursioniterative(weight,value,n,capacity,dpit)<<endl;;
    cout<<recursioniterativespace(weight,value,n,capacity)<<endl;;
    return 0;
}