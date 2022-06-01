#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>vec;
vector<int>currentcc;


void dfs(int node, vector<vector<int>>&G,vector<bool>&visited) {
    visited[node]=true;
    // cout<<node<<" ";
    currentcc.push_back(node);
    for(int neighbour: G[node]) {
        if(!(visited[neighbour]))
            dfs(neighbour, G,visited);
    }
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
    //  dfs(nodes, G,visited);

    for(int i=1;i<=N;++i) {
        if(visited[i])continue;
        currentcc.clear();
        dfs(i, G, visited);
        vec.push_back(currentcc);
        count++;
    }
    // cout<<count<<endl;
    
    for(auto ele : vec){
        for(auto cc: ele){
            cout<<cc<<" ";
        }
        cout<<endl;
    }

    return 0;
}
