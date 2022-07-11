#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// how many times the string2 appears int the string 1 


//recursion
//TC- Exponenetial Sc- O(N+M )
int stringmatching(int i, int j ,string str1 ,string str2 ){
    if(j<0)return 1;
    if(i<0)return 0;
    if(str1[i]==str2[j]){
        return stringmatching(i-1,j-1,str1,str2)+stringmatching(i-1,j,str1,str2);
    }
    return stringmatching(i-1,j,str1,str2);

}

// memoization
//TC-O(N*M) - SC- O(N*M) + O(N)
int stringmatchingmemo(int i, int j ,string str1 ,string str2 ,vector<vector<int>>&dp){
    if(j<0)return 1;
    if(i<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i]==str2[j]){
        return dp[i][j]=stringmatchingmemo(i-1,j-1,str1,str2,dp)+stringmatchingmemo(i-1,j,str1,str2,dp);
    }
    return dp[i][j]=stringmatchingmemo(i-1,j,str1,str2,dp);

}

// tabulation
int stringmatchingiterative(int n, int m ,string str1 ,string str2 ,vector<vector<int>>&dp){
   
    for(int i= 0;i<=n;i++)dp[i][0]=1;
    for(int j= 1;j<=m;j++)dp[0][j]=0;// here the j=1 so dont start it from 1  again
     for(int i =1;i<=n;i++){
        for(int j =1 ;j<=m;j++){
       if(str1[i-1]==str2[j-1]){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
     }
        else dp[i][j]=dp[i-1][j];
        }
     }
      
     return dp[n][m];
}

// space optimization
int stringmatchingspaceopti(int n, int m ,string str1 ,string str2 ){
     vector<int>prev(m+1,0),curr(m+1,0);
    prev[0]=1,curr[0]=1;
     for(int i =1;i<=n;i++){
        for(int j =1 ;j<=m;j++){
       if(str1[i-1]==str2[j-1]){
            curr[j]=prev[j-1]+prev[j];
     }
        else curr[j]=prev[j];
        }
        prev=curr;
     }

     return prev[m];
}


int main(){
    string str1="babgbag";
    string str2="bag";
    int n=str1.size();
    int m =str2.size();
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    vector<vector<int>>dpit(n+1,vector<int>(m+1,0));
     cout<<stringmatching(n-1,m-1,str1,str2)<<endl;;
     cout<<stringmatchingmemo(n-1,m-1,str1,str2,dp)<<endl;
     cout<<stringmatchingiterative(n,m,str1,str2,dpit)<<endl;
     cout<<stringmatchingspaceopti(n,m,str1,str2)<<endl;

    return 0;
}