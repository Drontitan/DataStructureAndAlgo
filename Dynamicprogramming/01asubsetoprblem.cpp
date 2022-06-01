#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

bool kanpsack(int arr[], int sum, int n)
{
    int i, j;
    bool t[n+1][sum+1];

    for (int i = 1; i <= sum; i++)
        t[0][i] = false;
    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < sum + 1; j++)
        {
             if (arr[i - 1] <= j)
            {
                t[i][j] =(t[i - 1][j - arr[i - 1]]|| t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[4] = {4, 3, 7, 10};
    int sum = 11;
    int n = 4;
    cout << kanpsack(arr,sum, n);
    return 0;
}
