#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// you have to burst the ballon in such a way that ex:- 3,4,5,6,1
// if you burst 5 then we will be get 4 coins:- 4*5*6 like wise
// so we have the to burst the ballon in such a way that the coins will be maximise

// if the ballon is bursted then when multiplying it will be not take  in to the count
// ex: -  if 3 is bursted then
// then we go for 4 then 3 is no available  4*5

/// here will go appossite of the previous problem we have solved like from the last element we will go up

// 3 1 5 8 // append 1 on both side

//  [3,1,5,8,]  3*1*5 =15
//  [3,5,8]   3*5*8 = 120
//  [3 ,8 ] 1*3*8 = 24
//   8 - 1 * 8* 1 =8

// here are taking vec[i-1]*vec[i]*vec[i+1]

// recursion
int burstballon(int i, int j, vector<int> vec)
{
    if (i > j)
        return 0;

    int maxa = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = vec[i - 1] * vec[ind] * vec[j + 1] + burstballon(i, ind - 1, vec) + burstballon(ind + 1, j, vec);
        maxa = max(maxa, cost);
    }

    return maxa;
}

// memoization
int burstballonmemo(int i, int j, vector<int> vec, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    int maxa = INT_MIN;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int ind = i; ind <= j; ind++)
    {
        int cost = vec[i - 1] * vec[ind] * vec[j + 1] + burstballonmemo(i, ind - 1, vec, dp) + burstballonmemo(ind + 1, j, vec, dp);
        maxa = max(maxa, cost);
    }

    return dp[i][j] = maxa;
}

// tabulation
int burstballoniterative(int n, vector<int> vec, vector<vector<int>> &dp)
{

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i>j)continue;
            int maxa = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = vec[i - 1] * vec[ind] * vec[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxa = max(maxa, cost);
            }
            dp[i][j] = maxa;
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> vec = {3, 1, 5, 8};
    int n = vec.size();
    vec.push_back(1);
    vec.insert(vec.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> dpit(n + 2, vector<int>(n + 2, 0));
    cout << burstballon(1, n, vec) << endl;
    cout << burstballonmemo(1, n, vec, dp) << endl;
    cout << burstballoniterative(n, vec, dpit) << endl;
    return 0;
}