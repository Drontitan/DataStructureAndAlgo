#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int t[10][10];
void memsetfun()
{
    memset(t, -1, sizeof(t));
}

int LCS(string x, string y, int n, int m)
{
      
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    if (x[n - 1] == y[m - 1])
    {
        return t[n][m]=1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return t[n][m]=max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    memsetfun();
    cout << LCS(x, y, n, m);
    return 0;
}