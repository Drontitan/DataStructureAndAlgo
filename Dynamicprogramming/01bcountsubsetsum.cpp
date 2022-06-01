#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int kanpsack(int arr[], int sum, int n)
{
    
    int t[n + 1][sum + 1];
       t[0][0]=1;
    for (int i = 1; i <= sum; i++)
        t[0][i] = 0;
    for (int i = 1; i <= n; i++)
        t[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j]) +(t[i - 1][j - arr[i - 1]]) ;
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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int arr[] = {1,1,2,2,3,3,4,4,5,5};
    int sum = 8;
    int n = 10;
    cout << kanpsack(arr, sum, n);
    return 0;
}
