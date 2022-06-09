#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    int totalsum = 0;
    int n = vec.size();
    for (int i = 0; i < n; i++)
        totalsum += vec[i];
    int k = totalsum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (vec[0] <= k)
        dp[0][vec[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[i - 1][target];
            bool take = false;
            if (vec[i] <= target)
            {
                take = dp[i - 1][target - vec[i]];
                dp[i][target] = take | nottake;
            }
        }
    }

    // dp[n-1][1... col]

    int mini = 1e9;
    for (int s1 = 0; s1 <= totalsum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            mini = min(mini, abs((totalsum - s1) - s1));
        }
    }

    cout << mini;

    return 0;
}