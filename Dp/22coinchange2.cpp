#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recursion
int coutnnumberofcoins(int i, vector<int> &vec, int target)
{
    if (i == 0)
    {
        if (target % vec[0] == 0)
            return 1;
        else
            return 0;
    }
    int notake = 0 + coutnnumberofcoins(i - 1, vec, target);
    int take = 0;
    if (vec[i] <= target)
    {
        take = coutnnumberofcoins(i, vec, target - vec[i]);
    }

    return notake + take;
}

// memoization
int coutnnumberofcoinsmemo(int i, vector<int> &vec, int target, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (target % vec[0] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][target] != -1)
        return dp[i][target];
    int notake = 0 + coutnnumberofcoinsmemo(i - 1, vec, target, dp);
    int take = 0;
    if (vec[i] <= target)
    {
        take = coutnnumberofcoinsmemo(i, vec, target - vec[i], dp);
    }

    return dp[i][target] = notake + take;
}

// tabulation
int coutnnumberofcoinsiterative(int n, vector<int> &vec, int target, vector<vector<int>> &dp)
{

    for (int t = 0; t <= target; t++)
    {
        dp[0][t] = (t % vec[0] == 0);
    }
    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notake = dp[i - 1][t];
            int take = 0;
            if (vec[i] <= t)
            {
                take = dp[i][t - vec[i]];
            }

            dp[i][t] = notake + take;
        }
    }
    return dp[n - 1][target];
}
//  space otimization
int coutnnumberofcoinsspaceotpi(int n, vector<int> &vec, int target)
{
    vector<int>prev(target+1,0),curr(target+1,0);
    for (int t = 0; t <= target; t++)
    {
        prev[t] = (t % vec[0] == 0);
    }
    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notake =prev[t];
            int take = 0;
            if (vec[i] <= t)
            {
                take =curr[t - vec[i]];
            }

           curr[t] = notake + take;
        }
        prev=curr;
    }
    return prev[target];
}

int main()
{
    vector<int> vec = {1, 2, 3};
    int target = 4;
    int n = vec.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    vector<vector<int>> dpit(n, vector<int>(target + 1, 0));
    cout << coutnnumberofcoins(n - 1, vec, target) << endl;
    cout << coutnnumberofcoinsmemo(n - 1, vec, target, dp) << endl;
    cout << coutnnumberofcoinsiterative(n, vec, target, dp) << endl;
    cout << coutnnumberofcoinsspaceotpi(n, vec, target) << endl;
    return 0;
}