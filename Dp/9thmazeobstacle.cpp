#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recursion solution

int mazeobstacle(vector<vector<int>>&vec,int i,int j){
    if(i==0&&j==0)return 1;
    if(i<0 || j<0)return 0;

    if(vec[i][j]==-1)return 0;
    int up =  mazeobstacle(vec,i,j-1);
    int left =  mazeobstacle(vec,i-1,j);
    return up +left;
}

//  memoization solution

int mazeobstaclememo(vector<vector<int>>&vec,int i,int j,vector<vector<int>>&dp){
    if(i==0&&j==0)return 1;
    if(i<0 || j<0)return 0;
    if(vec[i][j]==-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up =  mazeobstaclememo(vec,i,j-1,dp);
    int left =  mazeobstaclememo(vec,i-1,j,dp);
    return dp[i][j]=up +left;
}

// tabulation
int mazeobstacleiterative(vector<vector<int>>&vec,int n,vector<vector<int>>&dp){
    for(int i=0;i<n;i++){
        for (int j = 0; j <n; j++)
        {   
            if(vec[i][j]==-1)dp[i][j]=0;
            else if(i==0&&j==0)dp[i][j]=1;
            else{
                int up=0;
                int left=0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left =dp[i][j-1];
            dp[i][j]=up+left;
            }
        }
        
    }
    return dp[n-1][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>vec={{0,0,0,0},{0,-1,0,0},{0,0,0,0},{-1,0,0,0}};
    vector<vector<int>>dp(n,vector<int>(n,-1));
//   cout<< mazeobstacle(vec,n-1,n-1);
    //  cout<< mazeobstaclememo(vec,n-1,n-1,dp);
     cout<< mazeobstacleiterative(vec,n,dp);
    return 0;
}