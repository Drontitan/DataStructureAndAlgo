#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//  we taken the ind1 which is the index of the str1 it will be tracing it from the last ans if
// it is equal to the ind2 which is tracing the str2 then we got match increase the 1

// if not match we have two possiblity wither we can decrease the ind1 or ind2 so we have took the
// max of  both the calls

// dp on strings
// recursion
int longestcommonsub(string str1, string str2, int ind1, int ind2)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (str1[ind1] == str2[ind2])
    {
        return 1 + longestcommonsub(str1, str2, ind1 - 1, ind2 - 1); //  match
    }
    return max(longestcommonsub(str1, str2, ind1 - 1, ind2), longestcommonsub(str1, str2, ind1, ind2 - 1)); // notmatch
}

// memoization
int longestcommonsubmemo(string str1, string str2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (str1[ind1] == str2[ind2])
    {
        return dp[ind1][ind2] = 1 + longestcommonsubmemo(str1, str2, ind1 - 1, ind2 - 1, dp); //  match
    }
    return dp[ind1][ind2] = max(longestcommonsubmemo(str1, str2, ind1 - 1, ind2, dp), longestcommonsubmemo(str1, str2, ind1, ind2 - 1, dp)); // notmatch
}

// tabulation bottom to up
// shifying og the index so here 0  will be -1 ans n as n-1 and m as m-1
int longestcommonsubiterative(string str1, string str2, int n, int m, vector<vector<int>> &dp)
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
    return dp[n][m];
}

// space optimization
int longestcommonsubspaceopti(string str1, string str2, int n, int m)
{
    vector<int>prev(m+1,0),curr(m+1,0);
    for (int j = 0; j <= m; j++)
        prev[j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                curr[j] = 1 + prev[j - 1]; //  match
            }
            else curr[j] = max(prev[j], curr[j - 1]); // notmatch
        }
        prev=curr;
    }
    return prev[m];
}

int main()
{
    string str1 = "acdacavda";
    string str2 =str1;//here is the only trick we want to follow
     reverse(str2.begin(), str2.end());
    // else all part are same as lcs 
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    vector<vector<int>> dpit(n + 1, vector<int>(m + 1, 0));
    cout << longestcommonsub(str1, str2, n - 1, m - 1) << endl;

    cout << longestcommonsubmemo(str1, str2, n - 1, m - 1, dp) << endl;

    cout << longestcommonsubiterative(str1, str2, n, m, dpit)<<endl;
    cout << longestcommonsubspaceopti(str1, str2, n, m)<<endl;
    return 0;
}