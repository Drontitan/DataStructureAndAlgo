#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// from amy cell int the 1st row  from n*m grid to the last row to any cell 
// varible starting point to variable ending point


// recurion solution
//Tc - O(3*n) SC -O(N)
int maximumpathsum(vector<vector<int>>&vec,int i,int j){
     if(j<0||j>=vec[0].size())return -1e8;
     if(i==0)return vec[0][j];
     int up = vec[i][j]+maximumpathsum(vec,i-1,j);
     int rightdiagonal = vec[i][j]+maximumpathsum(vec,i-1,j+1);
     int leftdiagonal = vec[i][j]+maximumpathsum(vec,i-1,j-1);

     return max(up,max(rightdiagonal,leftdiagonal));
}
// memoization solution 
// TC- O(N*M)   Sc- O(N*M)+O(N)


int maximumpathsummemo(vector<vector<int>>&vec,int i,int j,vector<vector<int>>&dp){
     if(j<0||j>=vec[0].size())return -1e8;
     if(i==0)return vec[0][j];
     if(dp[i][j]!=-1)return dp[i][j];
     int up = vec[i][j]+maximumpathsummemo(vec,i-1,j,dp);
     int rightdiagonal = vec[i][j]+maximumpathsummemo(vec,i-1,j+1,dp);
     int leftdiagonal = vec[i][j]+maximumpathsummemo(vec,i-1,j-1,dp);

     return dp[i][j]=max(up,max(rightdiagonal,leftdiagonal));
}

// iterative solution 

int maximumpathsumiterative(vector<vector<int>>&vec,int n,int m,vector<vector<int>>&dp){
    for (int j = 0; j <m; j++) {
        dp[0][j]=vec[0][j];
    }
    for(int i=1;i<n;i++){
        for (int j = 0; j<m; j++){
            int up = vec[i][j]+dp[i-1][j];
            int rightdiagonal= vec[i][j];
            if(j+1<m) rightdiagonal +=dp[i-1][j+1];
            else rightdiagonal+=-1e8;
            int leftdiagonal= vec[i][j];
            if(j-1>0) leftdiagonal+=dp[i-1][j-1];
            else leftdiagonal+=-1e8;
            dp[i][j]=max(up,max(rightdiagonal,leftdiagonal));
        }
    }
    int maxi =-1e8;
    for (int j = 0; j <m; j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi; 
}

// space otpimization solution

int maximumpathsumspace(vector<vector<int>>&vec,int n,int m){
    vector<int>prev(n,0);
    vector<int>curr(n,0);
    for (int j = 0; j <m; j++) {
       prev[j]=vec[0][j];
    }
    for(int i=1;i<n;i++){
        for (int j = 0; j<m; j++){
            int up = vec[i][j]+prev[j];
            int rightdiagonal= vec[i][j];
            if(j+1<m) rightdiagonal +=prev[j+1];
            else rightdiagonal+=-1e8;
            int leftdiagonal= vec[i][j];
            if(j-1>0) leftdiagonal+=prev[j-1];
            else leftdiagonal+=-1e8;
            curr[j]=max(up,max(rightdiagonal,leftdiagonal));
        }
       prev=curr;
    }
    int maxi =-1e8;
    for (int j = 0; j <m; j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi; 
}



int main(){
    vector<vector<int>>vec={{1,7,8,2},{100,3,2,1,},{1,1,20,2},{1,2,2,1}};
    int n= vec.size();
    int m = vec[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi =-1e8;
    for (int j = 0; j <m; j++){
        // maxi=max(maxi,maximumpathsum(vec,n-1,j));
        // maxi=max(maxi,maximumpathsummemo(vec,n-1,j,dp));/
    }
    // cout<<maxi; 
    cout<<maximumpathsumspace(vec,n,m);
    return 0;
}