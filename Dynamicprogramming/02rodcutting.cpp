#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int knapsack(int length[], int price[], int N, int n)
{
    if ( N== 0 || n == 0)
    {
        return 0;
    }

    if (length[n - 1] <=N)
    {
        return max(price[n - 1] + knapsack(length, price, N - length[n - 1], n), knapsack(length, price, N, n - 1));
    }
    else if (length[n - 1] > N)
    {
        return knapsack(length,price, N, n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int length[]= {1,2, 3, 4,5,6,7,8};
    int price[] = {1, 5,8,9,10,17,17,20};
    int n = 8;//size
    int N = 8;// total lentgth we want  

    cout << knapsack(length, price, N, n);
    return 0;
}
