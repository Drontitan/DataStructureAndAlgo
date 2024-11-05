#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// SC-   O(N)+O(N)+O(N)

// TC-O(N) +(2*E)

void dfsvec(vector<int> &dfs, int visi[], int node, vector<int> adj[])
{

    visi[node] = 1;
    dfs.push_back(node);
    for (auto ele : adj[node])
    {
        if (!visi[ele])
        {
            dfsvec(dfs, visi, ele, adj);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec[n + 1];
    int visi[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    vector<int> dfs;
    int start = 1;
    dfsvec(dfs, visi, start, vec);

    for (auto ele : dfs)
        cout << ele << " ";

    return 0;
}