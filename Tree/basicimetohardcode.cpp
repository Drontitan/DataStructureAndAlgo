#include <bits/stdc++.h>
using namespace std;

const int m = 1e5 + 10;
typedef long long ll;

vector<int>subtree(m);


void dfs(vector<vector<int>> &G, int vertex, int parent = -1)
{       
     for (int child : G[vertex])
     {
          if (child == parent)
               continue;
         
          dfs(G, child, vertex);
     }
}

int main()
{
     int n, e;
     cin >> n;
     int a, b;
     vector<vector<int>> G(n + 1);
     for (int i = 0; i < e; ++i)
     {
          cin >> a >> b;
          G[a].push_back(b);
          G[b].push_back(a);
     }
     dfs(G, 1);
 

  
     return 0;
}