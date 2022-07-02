#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// time complexity is exponential because we are standing on the currnet index 
// recursion
int minimumcoins(vector<int>vec,int i,int target){
     if(i==0){
         if(target%vec[0]==0){
            return target/vec[0];
         }
         else return 1e9;
     }
     int nottake= minimumcoins(vec,i-1,target);
     int take=1e9;
     if(vec[i]<=target){
        take = 1+minimumcoins(vec,i,target-vec[i]);
     }

     return min(nottake,take);
}

// memomizatoin
int minimumcoinsmemo(vector<int>vec,int i,int target,vector<vector<int>>&dp){
     if(i==0){
         if(target%vec[0]==0){
            return target/vec[0];
         }
         else return 1e9;
     }
     if(dp[i][target]!=-1 )return dp[i][target];
     int nottake= minimumcoinsmemo(vec,i-1,target,dp);
     int take=1e9;
     if(vec[i]<=target){
        take = 1+minimumcoinsmemo(vec,i,target-vec[i],dp);
     }

     return dp[i][target]=min(nottake,take);
}
// tabulation
int minimumcoinsiterative(vector<int>vec,int n,int target,vector<vector<int>>&dpit){
      
     for(int t =0; t<=target ;t++){
         if(t%vec[0]==0)dpit[0][t]=t/vec[0];
         else dpit[0][t]=1e9;

     }
     for(int i=1; i<n;i++){
        for(int t =0 ; t<=target ;t++){
       int nottake= dpit[i-1][t];
      int take=1e9;
      if(vec[i]<=target){
        take = 1+dpit[i][t-vec[i]];
      }

            dpit[i][t]=min(nottake,take);
        }
     }

     return dpit[n-1][target];
   
}

// space optimization
int minimumcoinsspace(vector<int>vec,int n,int target){
      vector<int>prev(target+1,0),curr(target+1,0);
     for(int t =0; t<=target ;t++){
         if(t%vec[0]==0)prev[t]=t/vec[0];
         else prev[t]=1e9;

     }
     for(int i=1; i<n;i++){
        for(int t =0 ; t<=target ;t++){
       int nottake= prev[t];
      int take=1e9;
      if(vec[i]<=target){
        take = 1+prev[t-vec[i]];
      }

            curr[t]=min(nottake,take);
        }
        prev=curr;
     }

     return prev[target];
   
}



int main(){
    vector<int>vec={9,6,5,1};
    int target =11;  
    int n =vec.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    vector<vector<int>>dpit(n,vector<int>(target+1,0));
     cout<< minimumcoins(vec,n-1,target)<<endl;
     cout<< minimumcoinsmemo(vec,n-1,target,dp)<<endl;
     cout<< minimumcoinsiterative(vec,n-1,target,dpit)<<endl;
     cout<<minimumcoinsspace(vec,n,target);
    return 0;
}