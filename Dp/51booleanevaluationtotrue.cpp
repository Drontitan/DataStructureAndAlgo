#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// no of the ways we can make the exprssion to true
//  we can be given and &  or |  xor ^
// ex: - f&t|t^f

ll m = 100000007;

// recurion
ll booleanevaluation(int i, int j, int istrue, string vec)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (istrue)
            return vec[i] == 'T';
        else
            return vec[i] == 'F';
    }
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lf = booleanevaluation(i, ind - 1, 0, vec);
        int lt = booleanevaluation(i, ind - 1, 1, vec);
        int rf = booleanevaluation(ind + 1, j, 0, vec);
        int rt = booleanevaluation(ind + 1, j, 1, vec);
        if (vec[ind] == '&')
        {
            if (istrue)
                ways = (ways + (lt * rt) % m) % m;
            else
                ways = (ways + (lf * rt) % m + (rf * lt) % m + (rf * lf) % m) % m;
        }
        else if (vec[ind] == '|')
        {
            if (istrue)
                ways = (ways + (lt * rf) % m + (rt * lf) % m + (rt * lt) % m) % m;
            else
                ways = (ways + (lf * rf) % m) % m;
        }
        else if (vec[ind] == '^')
        {
            if (istrue)
                ways = (ways + (lt * rf) % m + (rt * lf) % m) % m;
            else
                ways = (ways + (lf * rf) % m + (lt * rt) % m) % m;
        }
    }
    return ways;
}

// recurion
ll booleanevaluationmemo(int i, int j, int istrue, string vec, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (istrue)
            return vec[i] == 'T';
        else
            return vec[i] == 'F';
    }
    if (dp[i][j][istrue] != -1)
        return dp[i][j][istrue];
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lf = booleanevaluationmemo(i, ind - 1, 0, vec, dp);
        int lt = booleanevaluationmemo(i, ind - 1, 1, vec, dp);
        int rf = booleanevaluationmemo(ind + 1, j, 0, vec, dp);
        int rt = booleanevaluationmemo(ind + 1, j, 1, vec, dp);
        if (vec[ind] == '&')
        {
            if (istrue)
                ways = (ways + (lt * rt) % m) % m;
            else
                ways = (ways + (lf * rt) % m + (rf * lt) % m + (rf * lf) % m) % m;
        }
        else if (vec[ind] == '|')
        {
            if (istrue)
                ways = (ways + (lt * rf) % m + (rt * lf) % m + (rt * lt) % m) % m;
            else
                ways = (ways + (lf * rf) % m) % m;
        }
        else if (vec[ind] == '^')
        {
            if (istrue)
                ways = (ways + (lt * rf) % m + (rt * lf) % m) % m;
            else
                ways = (ways + (lf * rf) % m + (lt * rt) % m) % m;
        }
    }
    return dp[i][j][istrue] = ways;
}

int main()
{
    string s = "T^F&F^T|T";
    int n = s.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    cout << booleanevaluation(0, n - 1, 1, s) << endl;
    cout << booleanevaluationmemo(0, n - 1, 1, s, dp) << endl;
    return 0;
}