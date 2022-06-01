#include <bits/stdc++.h>
using namespace std;

void dfs(int node, map<int, vector<int>>& G, set<int>& visited) {
    visited.insert(node);
    // cout << node << " ";
    for(int neighbour: G[node]) {
        if(visited.count(neighbour) == 0) {
            dfs(neighbour, G, visited);
        }
    }
}

int main() {
    int N,e;
    cin >>N>>e;

    map<int, vector<int>> G;

    for(int i = 0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // for(auto node: G) {
    //     cout << node.first << ": ";
    //     for(auto n: node.second) {
    //         cout << n << " ";
    //     }
    // }
     int nodes=1,count=0;
    set<int>visited;
    for(auto node: G) {
        if(visited.count(node.first) == 0) {
            dfs(nodes, G, visited);
            count++;
        }
    }
    cout<<count;
    // dfs(1, G, visited);

    // queue<int> q;
    // q.push(1);
    // visited.insert(1);

    // while(!q.empty()) {
    //     int node = q.front(); q.pop();
    //     cout << node << " ";
    //     for(int n: G[node]) {
    //         if(visited.count(n) == 0) {
    //             q.push(n);
    //             visited.insert(n);
    //         }
    //     }
    // }

    return 0;
}