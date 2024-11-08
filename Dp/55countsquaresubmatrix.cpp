#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// total number of the square int the matrix which are formed by 1
// here you can take all size square like 1 2 3 4 and all like this
//TC- O(N*M)  SC-O(N*M)  
int main()
{
    vector<vector<int>> mat = {{0, 1, 1,1}, {1, 1, 1,1}, {0,1, 1, 1}};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = mat[i][0];
    for (int j = 0; j < m; j++)
        dp[0][j] = mat[0][j];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            sum += dp[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}