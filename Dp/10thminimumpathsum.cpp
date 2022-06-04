#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recursion
int minimumpathsum(vector<vector<int>>&vec,int i,int j){
    if(i==0&&j==0)return vec[0][0];
    if(i<0||j<0)return 1e9;
     int up = vec[i][j]+minimumpathsum(vec,i-1,j);
     int left = vec[i][j]+minimumpathsum(vec,i,j-1);
    return min(up,left);
}

// memoization 

int minimumpathsummemo(vector<vector<int>>&vec,int i,int j,vector<vector<int>>&dp){
    if(i==0&&j==0)return vec[0][0];
    if(i<0||j<0)return 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
     int up = vec[i][j]+minimumpathsummemo(vec,i-1,j,dp);
     int left = vec[i][j]+minimumpathsummemo(vec,i,j-1,dp);
    return dp[i][j]=min(up,left);
}

// tabulation

int minimumpathsuiterative(vector<vector<int>>&vec,int n,int m,vector<vector<int>>&dp){
    for (int i = 0; i <n; i++)
    {
       for (int j = 0; j <m; j++)
       {     
           if(i==0&&j==0)dp[i][j]=vec[i][j];
           else{
           int up=vec[i][j];
           if(i>0)up+=dp[i-1][j];
           else up+=1e9;
           int left=vec[i][j];
           if(j>0)left+=dp[i][j-1];
           else left+=1e9;
           dp[i][j]=min(up,left);
           }
       }
    }
    
    return dp[n-1][m-1];
}


int main(){
    
    vector<vector<int>>vec={{5,9,6},{11,5,2}};
    int n=vec.size();
    int m= vec[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    //  cout<<minimumpathsum(vec,n,m);
    //  cout<<minimumpathsummemo(vec,n-1,m-1,dp);
     cout<<minimumpathsuiterative(vec,n,m,dp);
    return 0;
}