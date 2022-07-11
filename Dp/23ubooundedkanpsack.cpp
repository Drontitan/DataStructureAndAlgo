#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// infinite supply of the items but the capaity should not be overflowed okey 


// recursion
int unboundedknap(vector<int>weight,vector<int>value,int i,int target){
    if(i==0){
        if(weight[0]<=target)return (target/weight[i])*value[0];
        else return 0;
    }
    int nottake =0+unboundedknap(weight,value,i-1,target);
    int take =-1e9;
    if(weight[i]<=target){
        take = value[i]+unboundedknap(weight,value,i,target-weight[i]);
    }

    return max(nottake, take);
}

// memoization
int unboundedknapmemo(vector<int>weight,vector<int>value,int i,int target,vector<vector<int>>&dp){
    if(i==0){
        if(weight[0]<=target)return (target/weight[i])*value[0];
        else return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int nottake =0+unboundedknapmemo(weight,value,i-1,target,dp);
    int take =-1e9;
    if(weight[i]<=target){
        take = value[i]+unboundedknapmemo(weight,value,i,target-weight[i],dp);
    }

    return dp[i][target]=max(nottake, take);
}

// tabulation

int unboundedknapiterative(vector<int>weight,vector<int>value,int n,int target,vector<vector<int>>&dp){
    for(int w= 0 ;w<=target;w++){
          dp[0][w]= (w/weight[0])*value[0];
    }
     for(int i =1 ;i<n;i++){
        for(int w =0 ; w<=target; w++){
    int nottake =dp[i-1][w];
    int take =-1e9;
    if(weight[i]<=w){
        take = value[i]+dp[i][w-weight[i]];
    }
     dp[i][w]=max(nottake, take);
        }
     }
    return dp[n-1][target];
}

// space optimization
int unboundedknapspaceopti(vector<int>weight,vector<int>value,int n,int target){
    vector<int>prev(target+1,0),curr(target+1,0);
    for(int w= 0 ;w<=target;w++){
          prev[w]= (w/weight[0])*value[0];
    }
     for(int i =1 ;i<n;i++){
        for(int w =0 ; w<=target; w++){
    int nottake =prev[w];
    int take =-1e9;
    if(weight[i]<=w){
        take = value[i]+curr[w-weight[i]];
    }
    curr[w]=max(nottake, take);
        }
        prev=curr;
     }
    return prev[target];
}

int main(){
    vector<int>weight={2,4,6};
    vector<int>value={5,11,13};
    int n = weight.size();
    int target =10;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    vector<vector<int>>dpit(n,vector<int>(target+1,0));
    cout<<unboundedknap(weight,value,n-1,target)<<endl;
    cout<<unboundedknapmemo(weight,value,n-1,target,dp)<<endl;
    cout<<unboundedknapiterative(weight,value,n,target,dpit)<<endl;
    cout<<unboundedknapspaceopti(weight,value,n,target)<<endl;
    return 0;
}