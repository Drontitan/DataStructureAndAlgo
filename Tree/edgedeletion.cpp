#include <bits/stdc++.h>
using namespace std;
const int n=1e5+10 ;
const int m =1e9+7;
//In each query given v print the subtree of v and number of the even numbers int the subtree of v
vector<int>subtree_sum(n);
vector<int>val_vertex(n);
void dfs(int vertex, vector<vector<int>>&G,int par=-1) {
   // Taek action on the child before entering the vertex
     subtree_sum[vertex] += val_vertex[vertex];
    for(int child: G[vertex]) {
        if( child==par)continue;
       // take action on the child before entering the child node 
        dfs(child,G,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
       // take action on the child after exiting the child node 
    }  
       // take action on the child before exiting the vertex
}
    
int main() {
    int N,e;
    cin >>N;
    vector<vector<int>>G(N+1);

    for(int i = 0; i<N-1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
     dfs(1,G);
    long long ans=0;
     for (int i = 2; i <=n; i++)
     {
          int part1=subtree_sum[i];
          int part2= subtree_sum[1]-part1;
          ans = max(ans,(part1* 1ll * part2)%m);
     }
     cout<<ans<<endl;

    return 0;
}
