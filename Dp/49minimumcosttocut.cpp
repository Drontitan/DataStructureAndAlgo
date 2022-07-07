#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here i have minimised the cost of the cutting the stick
// now 0 1 2 3 4 7
// just put the 0  and lenght of the string at he back of the array
// now if we cut at the 3 then
// 0 1,2 3    3 4 7 so the cost will be cost[i-1]+cost[j+1]
// here we need i and j will be 2 pointer i will be at the start where cut is made and j will be last
// just above i here will be intially at 1 and j at 4
// after cuttin each length will have seprat i and j  ex:  i-1 j-2  i-4 j-4

// recursion
int costofcutting(int i, int j, vector<int> vec)
{
    if (i > j)
        return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = vec[j + 1] - vec[i - 1] + costofcutting(i, ind - 1, vec) + costofcutting(ind + 1, j, vec);
        mini = min(mini, cost);
    }
    return mini;
}
// memoization
int costofcuttingmemo(int i, int j, vector<int> vec, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    int mini = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int ind = i; ind <= j; ind++)
    {
        int cost = vec[j + 1] - vec[i - 1] + costofcuttingmemo(i, ind - 1, vec, dp) + costofcuttingmemo(ind + 1, j, vec, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
// tabulation
int costofcuttingiterative(int n, vector<int> vec, vector<vector<int>> &dp)
{
  
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i>j)continue;
            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = vec[j + 1] - vec[i - 1] + dp[i][ind-1] +dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    int v = vec.size();
    int n = 7;
    vec.push_back(n);
    vec.insert(vec.begin(), 0);
    sort(vec.begin(), vec.end()); // here the sort is imp so solve the subproblem independently
    // like if we cut the two parts will never have the connection in eachother
    vector<vector<int>> dp(v + 1, vector<int>(v + 1, -1));
    vector<vector<int>> dpit(v + 2, vector<int>(v + 2, 0));
    cout << costofcutting(1, v, vec) << endl;
    cout << costofcuttingmemo(1, v, vec, dp) << endl;
    cout << costofcuttingiterative(v,vec, dpit) << endl;
    return 0;
}
