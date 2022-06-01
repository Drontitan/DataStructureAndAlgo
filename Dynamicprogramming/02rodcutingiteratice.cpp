#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int kanpsack(int length[], int price[], int N, int n)
{
    int i, j;
    vector<vector<int>> t(n + 1, vector<int>(N + 1));

    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < N + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (length[i - 1] <= j)
            {
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][N];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8; // size
    int N = 8; // total lentgth we want
    cout << kanpsack(length, price, N, n);
    return 0;
}
