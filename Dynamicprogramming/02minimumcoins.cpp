#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int kanpsack(int coin[], int sum, int n)
{

    int t[n+1][sum+1];
    for (int i = 0; i <sum+1; i++){
        t[0][i] = INT_MAX-1;
    }
    for (int i = 1; i <n+1; i++){
        t[i][0]=0;
    }
    for (int i = 1; i <sum+1; i++)
    {
        if(i%coin[0]==0){
            t[1][i]=i/coin[0];
        }
        else{
        t[1][i]=INT_MAX-1;
        }
    }
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
             if (coin[i - 1] <= j)
            {
                t[i][j] = min(t[i][j - coin[i - 1]]+1, t[i - 1][j]);
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
    int coin[] = {9,3,5,3};
    int sum =11;
    int n = 4;
    cout << kanpsack(coin, sum, n);
    return 0;
}
