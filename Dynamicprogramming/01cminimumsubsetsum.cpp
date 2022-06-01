#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int kanpsack(int arr[], int sum, int n)
{
    int i, j;
    bool t[n + 1][sum + 1];

    
    for (int i = 0; i <= n; i++)
        t[i][0] = true;
     for (int i = 1; i <= sum; i++)
        t[0][i] = false;

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    int diff = INT_MAX;

     vector<int>vec;
    for (int j=0; j<=sum/2; j++)
    {
        if (t[n][j] == true)
        {
           vec.push_back(j);
        }
    }
    for (int i = 0; i <vec.size(); i++)
    {
        diff=min(diff,sum-(2*vec[i]));
    }
    
    return diff;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {1, 6,11,5};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum+=arr[i];
    }
    
    int n = 4;
    cout << kanpsack(arr, sum, n);
    return 0;
}
