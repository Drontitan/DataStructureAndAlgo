#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())
int t[50][50];
void memoset()
{
    memset(t, -1, sizeof(t));
}
int subsetcount(int arr[], int sum, int n)
{
 
    if (n == 0 || sum ==0)
    {
        return 1;
    }
    if (t[n][sum]!= -1)
    {
        return t[n][sum];
    }
    if (arr[n - 1] <= sum)
    {
        return t[n][sum] = subsetcount(arr, sum - arr[n - 1], n - 1)+subsetcount(arr, sum, n - 1);
    }
    else
    {
        t[n][sum] = subsetcount(arr, sum, n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 8;
    int n = 6;
    memoset();
    cout << subsetcount(arr, sum, n);
    return 0;
}
