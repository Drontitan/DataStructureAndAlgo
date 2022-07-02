#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// recursion solution
int twodpathscount(int i,int j){
    if(i==0 && j==0)return 1;
    if(i<0|| j<0)return 0;

    int up=twodpathscount(i-1,j);
    int left=twodpathscount(i,j-1);
    return up+left;
}

// memoization solution
int twodpathscountmemo(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0)return 1;
    if(i<0|| j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=twodpathscount(i-1,j);
    int left=twodpathscount(i,j-1);
    return dp[i][j]=up+left;
}

// tabulation way

int twodpathscountiterative(int n,int m,vector<vector<int>>&dp){

    for(int i=0;i<n;i++){
        for (int j = 0; j <m; j++)
        {   
            if(i==0&&j==0)dp[i][j]=1;
            else{
                int up=0;
                int left=0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left =dp[i][j-1];
            dp[i][j]=up+left;
            }
        }
        
    }
    return dp[n-1][m-1];
}

// space optimzation

int twodpathscountiterativespace(int n,int m){
    vector<int>prev(n,0);
    for(int i=0;i<n;i++){
        vector<int>curr(n,0);
        for (int j = 0; j <m; j++)
        {   
            if(i==0&&j==0)curr[j]=1;
            else{
                int up=0;
                int left=0;
            if(i>0) up = prev[j];
            if(j>0) left =curr[j-1];
            curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}


int main(){
    
    int n=3;
    vector<vector<int>>vec(n,vector<int>(n,-1));
    // cout<<twodpathscount(n-1,n-1);
    // cout<<twodpathscountmemo(n-1,n-1,vec);
    cout<<twodpathscountiterative(n,n,vec)<<endl;;
    cout<<twodpathscountiterativespace(n,n);
    return 0;
}