#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// you have given n you have to cut the rod and you are also the given the value of each lenth of the rod 
// array is given where length of each length is given 
// you have to cut he rod in suchway that it price should be maximize
/// any rod can be taken any number of time 

// recursion
// exponential
int rodcutting(vector<int>value,int i,int target){
    if(i==0){
       return target*value[0];
    }
    int nottake =0+rodcutting(value,i-1,target);
    int take =-1e9;
    int rodlength =i+1;
    if(rodlength<=target){
        take = value[i]+rodcutting(value,i,target-rodlength);
    }

    return max(nottake, take);
}

// memoization
// TC- O(N*N) SC- O(N*N)+O(N)
int rodcuttingmemo(vector<int>value,int i,int target,vector<vector<int>>&dp){
  if(i==0){
       return target*value[0];
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int nottake =0+rodcuttingmemo(value,i-1,target,dp);
    int take =-1e9;
      int rodlength =i+1;
    if(rodlength <=target){
        take = value[i]+rodcuttingmemo(value,i,target-rodlength,dp);
    }

    return dp[i][target]=max(nottake, take);
}

// tabulation

int rodcuttingiterative(vector<int>value,int n,int target,vector<vector<int>>&dp){
    for(int w= 0 ;w<=target;w++){
          dp[0][w]= (w)*value[0];
    }
     for(int i =1 ;i<n;i++){
        for(int w =0 ; w<=target; w++){
    int nottake =dp[i-1][w];
    int take =-1e9;
      int rodlength =i+1;
    if(rodlength<=w){
        take = value[i]+dp[i][w-rodlength];
    }
     dp[i][w]=max(nottake, take);
        }
     }
    return dp[n-1][target];
}

// space optimization
int rodcuttingspaceopti(vector<int>value,int n,int target){
    vector<int>prev(target+1,0),curr(target+1,0);
    for(int w= 0 ;w<=target;w++){
          prev[w]= (w)*value[0];
    }
     for(int i =1 ;i<n;i++){
        for(int w =0 ; w<=target; w++){
    int nottake =prev[w];
    int take =-1e9;
      int rodlength =i+1;
    if(rodlength<=w){
        take = value[i]+curr[w-rodlength];
    }
    curr[w]=max(nottake, take);
        }
        prev=curr;
     }
    return prev[target];
}


int main(){
//                    1,2,3,4,5
    vector<int>value={2,5,7,8,10};
    int n = value.size();
    int target =5;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    vector<vector<int>>dpit(n,vector<int>(target+1,0));
    cout<<rodcutting(value,n-1,target)<<endl;
    cout<<rodcuttingmemo(value,n-1,target,dp)<<endl;
    cout<<rodcuttingiterative(value,n,target,dpit)<<endl;
    cout<<rodcuttingspaceopti(value,n,target)<<endl;
    return 0;
}