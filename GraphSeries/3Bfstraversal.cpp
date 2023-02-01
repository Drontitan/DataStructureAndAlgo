#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// sapce complexity - O(3*N)
// time complexity - O(n)+O(2*E); // means we are traversin all the nodes and all the adjacenncy element in that

// it will taverse it total degrees and total degrees is equal to the 2 *edges

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


int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    int visi[n]={0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Bfs(adj, visi);

    return 0;
}