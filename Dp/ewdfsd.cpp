#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9;
int power(long long x, unsigned int y, int p)
{
    int res = 1;     
 
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
       
        if (y & 1)
            res = (res*x) % p;
 
    
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n , k;
        cin>>n>>k;
        if(log2(n)<k)cout<<n+1<<endl;
        else cout<<(int)pow(2,k)<<endl;
    }
    
    return 0;
}