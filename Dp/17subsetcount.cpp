#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// count the number of the subset whose sum are equal to the target

// recusrion

// TC = O(2^n) SC- O(N)
int subsetsum(vector<int> vec, int i, int sum)
{
    if (sum == 0)
        return 1;
    if (i == 0)
        return vec[0] == sum;
    int nottake = subsetsum(vec, i - 1, sum);
    int take = 0;
    if (vec[i] <= sum)
    {
        take = subsetsum(vec, i - 1, sum - vec[i]);
    }
    return take + nottake;
}

// memoization
// TC -O(N*sum )  SC- O(N*sum )+O(N)
int subsetsummemo(vector<int> vec, int i, int sum, vector<vector<int>> &dp)
{

    if (sum == 0)
        return 1;
    if (i == 0)
        return vec[0] == sum;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int nottake = subsetsummemo(vec, i - 1, sum, dp);
    int take = 0;
    if (vec[i] <= sum)
    {
        take = subsetsummemo(vec, i - 1, sum - vec[i], dp);
    }
    return dp[i][sum] = take + nottake;
}

// tabulation solution

int subsetsumiterative(vector<int> vec, int n, int sum, vector<vector<int>> &dp)
{

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    if (vec[0] <= sum)
        dp[0][vec[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sum; s++)
        {
            int nottake = dp[i - 1][s];
            int take = 0;
            if (vec[i] <= s)
            {
                take = dp[i - 1][s - vec[i]];
            }
            dp[i][s] = nottake + take;
        }
    }
    return dp[n - 1][sum];
}
// space optimization solution
int subsetsumiterativespace(vector<int> vec, int n, int sum)
{
    vector<int> prev(sum + 1, 0), curr(n + 1);
    prev[0]=0,curr[0]=0;
    if (vec[0] <= sum)
        prev[vec[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sum; s++)
        {
            int nottake = prev[s];
            int take = 0;
            if (vec[i] <= s)
            {
                take = prev[s- vec[i]];
            }
            curr[s] = nottake + take;
        }
        prev = curr;
    }
    return prev[sum];
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    int n = vec.size();
    int m = 5; // sum
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    vector<vector<int>> dpit(n, vector<int>(m + 1, 0));
    cout << subsetsum(vec, n - 1, m) << endl;
    cout << subsetsummemo(vec, n - 1, m, dp) << endl;
    cout << subsetsumiterative(vec, n, m, dpit) << endl;
    cout << subsetsumiterativespace(vec, n, m) << endl;

    return 0;
}