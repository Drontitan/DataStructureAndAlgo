#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll x,q,i=0;
    cin>>x;
    q=x;
    vector<vector<char>>mt(x,vector<char>(x,'0'));
    while(x--){
        ll a,b;
        cin>>a>>b;
        for(ll j=a;j<=b;j++){mt[i][j]='1';}
         i++;    
    }
    ios_base::sync_with_stdio(false);  
cin.tie(NULL); // flushes cout  
        ll n = mt.size();
        ll m = mt[0].size();
        ll dpit[n][m];
		memset(dpit , 0 , n * m * sizeof(ll));
        ll ans = 0;
		for(ll i = 0 ; i < n ; i++) {
            dpit[i][0] = mt[i][0] - 48;
            ans = max(ans , dpit[i][0]); 
        }
        for(ll j = 0 ; j < m ; j++) {
            dpit[0][j] = mt[0][j] - 48;
            ans = max(ans , dpit[0][j]);
        }
        for(ll i = 1 ; i < n ; i++) {
            for(ll j = 1 ; j < m ; j++) {
                if(mt[i][j] == '0') {
                    continue;
                }
                dpit[i][j] = min(dpit[i - 1][j] , min(dpit[i][j - 1] , dpit[i - 1][j - 1])) + 1;
                // cout << i << " " <<  j << " " << dpit[i][j] << endl;
                ans = max(ans , dpit[i][j] * dpit[i][j]);
            }
        }
     
   cout<<ans<<endl;
    return 0;
}