#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ? it matches with any single character
// *  it matches with 0 or more character
//// if there are matching you need to return a true4

// for * we will try all possible ways so it is an recursion
//  ex: - abc*fg    abcdefg   *->can take no char or e or de or cde then it will be true further

// recursion
//TC- exponential
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
        return wildcardmatching(i - 1, j, s1, s2)    // here we are not taking anything for *
               | wildcardmatching(i, j - 1, s1, s2); // here we are taking 1 2 or 3 or many cases for *
    }
    return false;
}

// memoization
//TC- O( N*M ) 
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
bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = isAllStars(S1, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (S1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];

}
// space optimization



int main()
{


    string s1 ="";
    string s2 = "******";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    cout << wildcardmatching(n - 1, m - 1, s1, s2) << endl;
    cout << wildcardmatchingmemo(n - 1, m - 1, s1, s2, dp) << endl;
    cout << wildcardMatching(s1, s2) << endl;
    return 0;
}