#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void Bfs(vector<int> vec[], int visi[])
{
    vector<int> bfs;
    visi[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto ele : vec[node])
        {
            if (!visi[ele])
            {
                q.push(ele);
                visi[ele] = 1;
            }
        }
    }
    for (auto ele : bfs)
        cout << ele << " " ;
}

ll check(int i,int n,ll c,ll ele,vector <pair <ll,ll>> &vec,vector <vector <ll>> &dp){
   
   
    if(i==n){
        return 0;
    }
   
    if(dp[i][ele]!=-1){
        return dp[i][ele];
    }
    if(ele<vec[i].first){
       
        return -1;
    }
   
       
        ll left=(c-(ele-vec[i].first))*vec[i].second+500+check(i+1,n,c,c,vec,dp);
       ll right=check(i+1,n,c,ele-vec[i].first,vec,dp);
   
    ll res=1e12;
   
    if(left!=-1){
        res=min(res,left);
    }
    if(right!=-1){
        res=min(res,right);
    }
   
    return dp[i][ele]=res;
   
}

void solve(){
    ll x,y,r;
    cin>>x>>y>>r;
    ll ans=y*r;
    ll ele=y;
    vector <pair <ll,ll>> vec;
    for(int i=0;i<x;i++){
        ll u,v;
        cin>>u>>v;
        vec.push_back({u,v});
    }
   
    vector <vector <ll>> dp(x+1,vector <ll> (y+1,-1));
    cout<<check(0,x,y,ele,vec,dp)+ans<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}