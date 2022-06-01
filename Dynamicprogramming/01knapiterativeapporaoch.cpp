#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())


int kanpsack(int wt[], int val[], int w, int n)
{
    int i,j;
    vector<vector<int>> t(n + 1, vector<int>(w+ 1));

    for ( i = 0; i < n + 1; i++)
    {
        for ( j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
         
     }
      return t[n][w];

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int wt[4] = {1, 3, 4, 4};
    int val[4] = {1, 4, 5, 7};
    int w = 10;
    int n = 4;
    cout << kanpsack(wt, val, w, n);
    return 0;
}
