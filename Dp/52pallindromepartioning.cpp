#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// find the minimum partition require to make the string as the pallindrome 
// bab|cbc|abba|c|a here i have done 4 partitions 

//  front partitions : -

//  what we will do that we will traverse from left to right like taking b then a then b as long the string 
// will say it is pallindrome then mark the pallindrome then move i to where we have stop
// check next part of the string here from cbc like that

bool isPallindrome(int i,int j ,string s){
  
    while(i>j){
        if(s[i]!=s[j]){ cout<<"lala<"<<endl;return false;}
        i++;j--;
    }
    return true;
}

int partitionpallin(int i,int n,string &s){
    if(i==n)return 0;
    
    int mini=INT_MAX;
    for(int ind = i; ind<n;ind++){

      if(isPallindrome(i,ind,s)){
        int cost =1+partitionpallin(ind+1,n,s);
        mini = min(mini,cost);
      }
    }
    return mini;
}

//memoisation
int partitionpallinmemo(int i,int n,string &s,vector<int>&dp){
    if(i==n)return 0;
    
    int mini=INT_MAX;
    if(dp[i]!=-1)return dp[i];
    for(int ind = i; ind<n;ind++){

      if(isPallindrome(i,ind,s)){
        int cost =1+partitionpallinmemo(ind+1,n,s,dp);
        mini = min(mini,cost);
      }
    }
    return dp[i]=mini;
}
//tabulation
int partitionpalliniterative(int n,string &s,vector<int>&dp){
    
    dp[n]=0;
    for(int i=n-1 ;i>=0;i--){
       int mini=INT_MAX;

    for(int ind = i; ind<n;ind++){

      if(isPallindrome(i,ind,s)){

        int cost =1+dp[ind+1];
        mini = min(mini,cost);
      }
    }
    dp[i]=mini;
   }
   return dp[0]-1;
}
  
int main(){
    string str="abcd";
    int n = str.size();
    // vector<int>dp(n,-1);
    vector<int>dp(n+1,0);
    // cout<<partitionpallin(0,n,s)-1<<endl;
    // cout<<partitionpallinmemo(0,n,s,dp)-1<<endl;
    // cout<<partitionpalliniterative(n,s,dpit)<<endl;
       dp[n]=0;
       for(int i=n-1 ;i>=0;i--){
       int mini=INT_MAX;
    for(int j= i; j<n;j++){
      if(isPallindrome(i,j,str)){        
        int cost = (1+dp[j+1]);
        mini = min(mini,cost);
        cout<<mini<<endl;
      }
    }
    dp[i]=mini;
   }
    cout<< dp[0]-1;
    return 0;   
}