#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

minimum path sum 
in triangle

1

2 3
  |\
3 4 5
  |\ |\  like this we can move 
6 7 8 9 


we can move directly down or diafonally botoom manner  only 

*/
// recursion
int countminpath(vector<vector<int>>&vec,int i,int j,int n){
    if(i==n-1)return vec[n-1][j];
    int down = vec[i][j]+countminpath(vec,i+1,j,n);
    int diagonal =vec[i][j]+countminpath(vec,i+1,j+1,n);
    return min(down ,diagonal);
}

// memoization
int countminpathmemo(vector<vector<int>>&vec,int i,int j,int n,vector<vector<int>>&dp){
    if(i==n-1)return vec[n-1][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int down = vec[i][j]+countminpathmemo(vec,i+1,j,n,dp);
    int diagonal =vec[i][j]+countminpathmemo(vec,i+1,j+1,n,dp);
    return dp[i][j]=min(down ,diagonal);
}

// iterative solution

int countminpathiterative(vector<vector<int>>&vec,int n,vector<vector<int>>&dp){
    for (int j = 0; j <n; j++)
    {
       dp[n-1][j]=vec[n-1][j];
    }
    for (int i = n-2; i>=0; i--)
    {
     for (int j = i; j >=0; j--)
     {
        int down = vec[i][j]+dp[i+1][j];
        int diagonal =vec[i][j]+dp[i+1][j+1];
        dp[i][j]=min(down,diagonal);
     }
     
    }
    return dp[0][0];
}


//  space optimization
int countminpathspaceoptimization(vector<vector<int>>&vec,int n){
  vector<int>front(n,0),curr(n,0);
    for (int j = 0; j <n; j++)
    {
       front[j]=vec[n-1][j];
    }
    for (int i = n-2; i>=0; i--)
    {
     for (int j = i; j >=0; j--)
     {
        int down = vec[i][j]+front[j];
        int diagonal =vec[i][j]+front[j+1];
        curr[j]=min(down,diagonal);
     }
        front=curr;
     
    }
    return front[0];
}



int main(){
      vector<vector<int>>vec={{1},{3,2},{6,7,8},{11,10,9,12}};
      int n= vec.size();
      vector<vector<int>>dp(n,vector<int>(n,-1));
    //   cout<<countminpath(vec,0,0,4);
      // cout<<countminpathmemo(vec,0,0,n,dp);
      // cout<<countminpathiterative(vec,n,dp);
      cout<<countminpathspaceoptimization(vec,n);
    return 0;
}