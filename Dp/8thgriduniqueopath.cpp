#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// you are standing at 0,0 and the matrix is of size m*n you have reach m-1,n-1
// you can either go down or right find the total number of the unique ways 


// we have gone in reverse order and taken up and left 
// recursion solution

// exponential  TC- O(2^n*m)  sc-pathlenth 

int twodpathscount(int i,int j){
    if(i==0 && j==0)return 1;
    if(i<0|| j<0)return 0;

    int up=twodpathscount(i-1,j);
    int left=twodpathscount(i,j-1);
    return up+left;
}


//Tc - O(N*M) // SC- O(n-1)+O(m-1)+O(N*M)
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
    vector<vector<int>>vecit(n,vector<int>(n,0));
    // cout<<twodpathscount(n-1,n-1)<<endl;
    // cout<<twodpathscountmemo(n-1,n-1,vec)<<endl;
    cout<<twodpathscountiterative(n,n,vecit)<<endl;
    cout<<twodpathscountiterativespace(n,n);
    return 0;
}