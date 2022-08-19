#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// SC-   O(N)+O(N)

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
    int count=0;
    for(int i=1 ;i<=n;i++){
      if(!visi[i]){
        count++;
     dfsvec(dfs, visi, i, vec);
     }
    }

    for (auto ele : dfs)
        cout << ele << " ";
        cout<<endl;
        cout<<count<<endl;

    return 0;
}

// oklets talk about something trash now 
for(auto ele: mp ){
    cout<<ele<< " ";
}
cout<<endl;
for(int =0 ;i< n; i++){
    cout<<vec[i][j]<<" ";
}
cout<<"\n";
