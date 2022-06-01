#include <bits/stdc++.h>
using namespace std;
const int n=1e5+10 ;

//In each query given v print the subtree of v and number of the even numbers int the subtree of v
int depth[n];
void dfs(int vertex, vector<vector<int>>&G,int par=-1) {
   // Taek action on the child before entering the vertex
     
    for(int child: G[vertex]) {
        if( child==par)continue;
       // take action on the child before entering the child node 
       depth[child]=depth[vertex]+1;
        dfs(child,G,vertex);
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
    int max_depth=-1;
    int max_d_node;
     for(int i=1;i<=n;++i){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_d_node=i;
        }
        depth[i]=0;
    }
     dfs(max_d_node,G);
      max_depth=-1;
      for(int i=1;i<=n;++i){
        if(max_depth<depth[i]){
            max_depth=depth[i];
        }
    }
    cout<<max_depth<<endl;
    return 0;
}
