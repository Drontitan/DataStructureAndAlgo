#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



void dfsvec(vector<int> &dfs, int visi[], int node, vector<int> adj[],vector<int>&parent)
{

    visi[node] = 1;
    dfs.push_back(node);
    for (auto ele : adj[node])
    {
        if (!visi[ele])
        {
      
            parent[ele]=node;
            dfsvec(dfs, visi, ele, adj,parent);
        }
      
    }
}
int main(){
      int n,e;
      cin>>e;
      n=e+1;
      vector<int>vec[n+1];
      for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
      }
      
      int visi[n+1]={0};
      int start=0;
      vector<int>dfs;
      vector<int>parent(n+1);
      dfsvec(dfs,visi,start,vec,parent);

        for(int i=0 ;i <n; i++){
            cout<<parent[i]<<" ";
        }
        // for(auto ele :dfs )cout<<ele<<" ";


    return 0;
}