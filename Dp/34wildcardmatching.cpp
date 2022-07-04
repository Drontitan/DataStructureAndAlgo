#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ? it matches with any single character
// *  it matches with 0 or more character
//// if there are matching you need to return a true4

// for * we will try all possible ways so it is an recursion
//  ex: - abc*fg    abcdefg   *->can take no char or e or de or cde then it will be true further

// recursion
int wildcardmatching(int i, int j, string s1, string s2)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int t = 0; t <= i; t++)
        {
            if (s1[t] != '*')
                return false; // if string 1 is not empty it has to be all *
        }
        return true;
    }
    if (s1[i] == s2[j] || s1[i] == '?')
    {
        return wildcardmatching(i - 1, j - 1, s1, s2);
    }
    if (s1[i] == '*')
    {
        return wildcardmatching(i - 1, j, s1, s2)    // here we are not takinf anytin for *
               | wildcardmatching(i, j - 1, s1, s2); // here we are taking 1 2 or 3 or many cases for *
    }
    return false;
}

// memoization
int wildcardmatchingmemo(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int t = 0; t <= i; t++)
        {
            if (s1[t] != '*')
                return false; // if string 1 is not empty it has to be all *
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j] || s1[i] == '?')
    {
        return dp[i][j] = wildcardmatchingmemo(i - 1, j - 1, s1, s2, dp);
    }
    if (s1[i] == '*')
    {
        return dp[i][j] = wildcardmatchingmemo(i - 1, j, s1, s2, dp)    // here we are not takinf anytin for *
                          | wildcardmatchingmemo(i, j - 1, s1, s2, dp); // here we are taking 1 2 or 3 or many cases for *
    }
    return false;
}

// tabulation
int wildcardmatchingiterative(int n, int m, string s1, string s2, vector<vector<bool>> &dp)
{
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int t = 0; t <= i; t++)
        {
            if (s1[t] != '*')
                flag = false; // if string 1 is not empty it has to be all *
            else
                break;
        }
        dp[i][0] = flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j]    // here we are not takinf anytin for *
                           | dp[i][j - 1]; // here we are taking 1 2 or 3 or many cases for *
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// space optimization

int main()
{

    string s1 = "ab*fg";
    string s2 = "abcdefg";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    vector<vector<bool>> dpit(n + 1, vector<bool>(m + 1, false));
    cout << wildcardmatching(n - 1, m - 1, s1, s2) << endl;
    cout << wildcardmatchingmemo(n - 1, m - 1, s1, s2, dp) << endl;
    cout << wildcardmatchingiterative(n, m, s1, s2, dpit) << endl;
    return 0;
}