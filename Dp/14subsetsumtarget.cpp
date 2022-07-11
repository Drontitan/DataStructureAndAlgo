#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// if there exit the subset that give the sum equal to the target 

// recusrion 
// O( 2^n) -SC O(N) 
bool subsetsum(vector<int>vec,int i,int target){
    
   if(target==0)return true;
   if(i==0)return vec[0]==target; // if we are standing at the o th index can the target can be achived if and only if the target equals that element 
   bool  nottake= subsetsum(vec,i-1,target);
   bool take= false;
   if(vec[i]<=target){
       take= subsetsum(vec,i-1,target-vec[i]);
   }
     return take| nottake;
}


// memoization 
// TC - O(N*target)  SC- (N*target) 
bool subsetsummemo(vector<int>vec,int i,int target,vector<vector<int>>&dp){
    
   if(target==0)return true;
   if(i==0)return vec[0]==target;
   if(dp[i][target]!=-1)return dp[i][target];
   bool  nottake= subsetsummemo(vec,i-1,target,dp);
   bool take= false;
   if(vec[i]<=target){
       take= subsetsummemo(vec,i-1,target-vec[i],dp);
   }
     return  dp[i][target]=take| nottake;
}

// tabulation
bool subsetsumiterative(vector<int>vec,int n,int k,vector<vector<bool>>&dp){
    
  for (int i = 0; i <n; i++){
    dp[i][0]=true;// any moment the target is 0 then the base case we will be following 
  }
  dp[0][vec[0]]=true;
  for(int i= 1;i<n;i++){
      for(int target=1;target<=k;target++){
           bool  nottake= dp[i-1][target];
        bool take= false;
       if(vec[i]<=target){
        take= dp[i-1][target-vec[i]];
           dp[i][target]= take| nottake;
      }
  }
}
   return dp[n-1][k];
  
}

//  space optimization
bool subsetsumspace(vector<int>vec,int n,int k){
 vector<bool>prev(k+1,0),curr(k+1,0);
 prev[0]=curr[0]=true;
 prev[vec[0]]=true;
  for(int i= 1;i<n;i++){
      for(int target=1;target<=k;target++){
           bool  nottake= prev[target];
        bool take= false;
       if(vec[i]<=target){
        take= prev[target-vec[i]];
           curr[target]= take| nottake;
      }
  }
      prev=curr;
}
   return prev[k];
  
}

int main(){
    vector<int>vec={1,2,3,4};
    int n=vec.size();
    int m= 4;// target
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    vector<vector<bool>>dpit(n,vector<bool>(m+1,0));
     cout<<subsetsum(vec,vec.size()-1,m)<<endl;
     cout<<subsetsummemo(vec,vec.size()-1,m,dp)<<endl;
     cout<<subsetsumiterative(vec,vec.size(),m,dpit)<<endl;
     cout<<subsetsumspace(vec,vec.size(),m);
    return 0;
}