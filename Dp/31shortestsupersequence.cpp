#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



// here the two string cobime to make the one string 
//  ex- "brute"  "groot"
// "brutegroot" :- this can be the string but we have to take the shortest common supersquence
// so the string will be : ----          "bgruoote" // order should be same 
void longestcommonsubiterative(string str1, string str2, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1]; //  match
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // notmatch
        }
    }
   int len = dp[n][m];
   string ans ="";


   int i =n,j=m;
   while(i>0 && j>0){
    if(str1[i-1]==str2[j-1]){
        ans+=str1[i-1];
       i-- , j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
        ans+=str1[i-1];
        i--;
    }
    else {
         ans+=str2[j-1];
         j--;
    }
       
   }
   while(i>0){
    ans+=str1[i-1];
    i--;
    }
   while(j>0){
    ans+=str1[j-1];
    j--;
    }

   reverse(ans.begin(),ans.end());
   cout<<ans<<endl;
}


int main()
{
    string str1 = "abcde";
    string str2 = "bdgek";
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dpit(n + 1, vector<int>(m + 1, 0));

     longestcommonsubiterative(str1, str2, n, m, dpit);

    return 0;
}