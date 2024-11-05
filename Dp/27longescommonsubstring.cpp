#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// i have to find the longest commin substring 


//  we taken the ind1 which is the index of the str1 it will be tracing it from the last ans if
// it is equal to the ind2 which is tracing the str2 then we got match increase the 1

// if not match we have two possiblity either we can decrease the ind1 or ind2 so we have took the
// max of  both the calls

// dp on strings


// here form the tabulation table we have found the key towards the answer diagonal if matched and 
// added +1 or else if not matched then max of the two diagonals 




// tabulation bottom to up
// shifting fg the index so here 0  will be -1 ans n as n-1 and m as m-1

// here we have ans through the dp table that was generated 
int longestcommonsubiterative(string str1, string str2, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
        int ans=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1]; //  match
                ans =max(ans,dp[i][j]);
            }
            else dp[i][j] = 0; // notmatch
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //        cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int i=n,j=m;
    // cout<<dp[i-1][j-1]<<endl;
    string s="";
    while(i>0 && j>0){
      if(dp[i][j]==ans )break;
      else if(dp[i-1][j]>dp[i][j-1]) i--;
       else j--;
    //   i--,j--;  
     }
        // cout<<i<<j<<endl;
         while(i>0 && j>0 ){
         if(str1[i-1]==str2[j-1]){
             s+=str1[i-1];
             i--,j--;
         }
         else break;
     }
     cout<<s<<endl;
   return ans;
}


int main()
{
    string str1 = "codeforces";
    string str2 = "atcoder";
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dpit(n + 1, vector<int>(m + 1, 0));

     cout<<longestcommonsubiterative(str1, str2, n, m, dpit);

    return 0;
}