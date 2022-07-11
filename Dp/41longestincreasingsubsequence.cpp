#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// find the longest increasing subsequnce ex : - 10,2,3,6,5,7,9,1
// ans - 2,3,5,7,9,

// recursion
//TC- O(2^N) SC: - O(N)
int longestincreasing(int i, int prev, vector<int> &vec)
{

    if (i == vec.size())
        return 0;

    int len = 0 + longestincreasing(i + 1, prev, vec); // not taking the ele
    if (prev == -1 || vec[i] > vec[prev])
    {   //  taking the  ele  with checking that it ele shoould be greater than
        // it previous once
        len = max(len, 1 + longestincreasing(i + 1, i, vec));
    }
    return len;
}

// memomization
//  Tc: -O(N*N)  SC-O(N*N) + O( N)
 int longestincreasingmemo(int i, int prev, vector<int> &vec, vector<vector<int>> &dp)
{

    if (i == vec.size())
        return 0;
    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1]; // here in the dp we can not have previous as -1
    // so ther will be 0 based indexing so we have taken 1 index more
    int len = 0 + longestincreasingmemo(i + 1, prev, vec, dp); // not taking the ele
    if (prev == -1 || vec[i] > vec[prev])
    {   //  taking the  ele  with checking that it ele shoould be greater than
        // it previous once
        len = max(len, 1 + longestincreasingmemo(i + 1, i, vec, dp));
    }
    return dp[i][prev + 1] = len;
}

// tabulation
int longestincreasingiterative(int n, vector<int> &vec, vector<vector<int>> &dp)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {

            int len = 0 + dp[i + 1][j + 1]; // not taking the ele
            if (j == -1 || vec[i] > vec[j])
            {   //  taking the  ele  with checking that it ele shoould be greater than
                // it previous once
                len = max(len, 1 + dp[i + 1][i + 1]);
            }
            dp[i][j + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}

// spaceoptimization
int longestincreasingspaceoptimization(int n, vector<int> &vec){
    vector<int>prev(n+1,0),curr(n+1,0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {

            int len = 0 + prev[j + 1]; // not taking the ele
            if (j == -1 || vec[i] > vec[j])
            {   //  taking the  ele  with checking that it ele shoould be greater than
                // it previous once
                len = max(len, 1 + prev[i + 1]);
            }
            curr[j + 1] = len;
        }
        prev=curr;
    }
    return prev[-1 + 1];
}

int main()
{
    vector<int> vec = {10, 2, 3, 6, 5, 7, 9, 1};
    int n = vec.size();
    vector<vector<int>> dp(n, vector<int>(n + 0, -1));
    vector<vector<int>> dpit(n + 1, vector<int>(n + 1, 0));
    cout << longestincreasing(0, -1, vec) << endl;
    cout << longestincreasingmemo(0, -1, vec, dp) << endl;
    cout << longestincreasingiterative(n, vec, dpit)<<endl;
    cout << longestincreasingspaceoptimization(n, vec);
    return 0;
}