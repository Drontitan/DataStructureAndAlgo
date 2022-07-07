#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// given the dimension of the matrix we have multiply them in such a way such that can be done in the
// minimum operations
// a*b  b*c then a*b*c is the total number of the operation

// this can be solved by the partition dp

// recursion
int matrixchain(int i, int j, vector<int> vec)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = vec[i - 1] * vec[k] * vec[j] + matrixchain(i, k, vec) + matrixchain(k + 1, j, vec);
        if (steps < mini)
            mini = steps;
    }
    return mini;
}

//  Tc :- O{N*N*N} O(N^3)   Sc-O(N^2)+auxilary
// memoization
int matrixchainmemo(int i, int j, vector<int> vec, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i; k < j; k++)
    {
        int steps = vec[i - 1] * vec[k] * vec[j] + matrixchain(i, k, vec) + matrixchain(k + 1, j, vec);
        if (steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
}

// tabulation
int matrixchainiterative(int n,vector<int> vec, vector<vector<int>> &dp)
{
   for(int i= 0; i<n;i++)dp[i][i]=0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int mini = 1e9;
                for (int k = i; k < j; k++)
                {
                    int steps = vec[i - 1] * vec[k] * vec[j] + dp[i][k] + dp[k + 1][j];
                    if (steps < mini)
                        mini = steps;
                }
                dp[i][j] = mini;
            }
        }
    }

    return dp[1][n-1];
}

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};
    int n = vec.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> dpit(n, vector<int>(n, 0));
    cout << matrixchain(1, n - 1, vec) << endl;
    cout << matrixchainmemo(1, n - 1, vec, dp) << endl;
    cout << matrixchainiterative(n, vec, dpit) << endl;

    return 0;
}