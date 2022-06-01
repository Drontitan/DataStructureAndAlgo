#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>&G,vector<bool>&visited,int par) {
    visited[node]=true;
    // cout<<node<<" ";
    bool isloopsexist=false;
    for(int neighbour: G[node]) {
        if(visited[neighbour] && neighbour==par)continue;
        if(visited[neighbour])return true;
       isloopsexist!=dfs(neighbour, G,visited,node);

    }
            return isloopsexist;
}

int main() {
    int N,e;
    cin >>N>>e;
    vector<vector<int>>G(N+1);

    for(int i = 0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
     vector<bool>visited(N+1, false);
     int count=0;

    bool isloopsxist=false;
    for(int i=1;i<=N;++i) {
        if(visited[i])continue;
        if(dfs(i, G, visited,0)){
            isloopsxist=true;
        }
    }
    cout<<isloopsxist<<endl;

    return 0;
}
