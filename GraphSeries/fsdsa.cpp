#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll  M =1e9+7;

void find_paths(vector<vector<ll> >& paths,vector<ll>& path,vector<ll> parent[],ll n, ll u){

	if (u == -1) {
		paths.push_back(path);
		return;
	}
	for (ll par : parent[u]) {
		path.push_back(u);
		find_paths(paths, path, parent,
				n, par);
		path.pop_back();
	}
}

void bfs(vector<ll> adj[],
		vector<ll> parent[],
		ll n, ll start)
{

	vector<ll> dist(n, INT_MAX);
	queue<ll> q;
	q.push(start);
	parent[start] = { -1 };
	dist[start] = 0;

	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		for (ll v : adj[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				q.push(v);
				parent[v].clear();
				parent[v].push_back(u);
			}
			else if (dist[v] == dist[u] + 1) {
				parent[v].push_back(u);
			}
		}
	}
}

void prllans(vector<ll> adj[],ll n, ll start, ll end,vector<ll>&ans){
	vector<vector<ll> > paths;
	vector<ll> path;
	vector<ll> parent[n];
	bfs(adj, parent, n, start);
	find_paths(paths, path, parent, n, end);

	for (auto v : paths) {
		reverse(v.begin(), v.end());
		for (ll u : v)ans.push_back(u);
	}
}
int main()
{

    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    unordered_map<ll,ll>mp;
    for(ll i=1;i<=n; i++){
        ll x;
        cin>>x;
        mp[i]=x;
    }

       vector<ll>vec[n+1];
   
    for (ll i = 0; i <n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    ll b;
    cin>>b;
    // cout<<"hello"<<" ";
    while(b--){
        ll t,x,y;
        cin>>t>>x>>y;
        if(t==1)mp[x]=y;
        else {
            long long sum=1;
               vector<ll>res;
                prllans(vec, n+1, x,y,res);
                for(auto it :res){
                    // cout<<it<<" ";
                    sum=(sum%M*mp[it]%M)%M;
                    // cout<<sum<<" ";
                }
                cout<<sum<<endl;
        }
    }
    }
    return 0;

}