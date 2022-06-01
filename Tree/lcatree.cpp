#include <bits/stdc++.h>
using namespace std;
const int n=1e5+10 ;

//In each query given v print the subtree of v and number of the even numbers int the subtree of v
int par[n];
void dfs(int vertex, vector<vector<int>>&G,int parent=-1) {
   // Taek action on the child before entering the vertex
      par[vertex]=parent;
    for(int child: G[vertex]) {
        if( child==parent)continue;
       // take action on the child before entering the child node 
        dfs(child,G,vertex);
       // take action on the child after exiting the child node 
    }  
       // take action on the child before exiting the vertex
}
    
vector<int>path(int v){
    vector<int>ans;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;

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

     int x,y;
     cin>>x>>y;
     vector<int> path_x =path(x);
     vector<int> path_y =path(y);
      
     int minlen= min(path_x.size(),path_y.size());

     int lca = -1;
     for (int i =1; i <=n; ++i)
     {
         if(path_x[i]==path_y[i]){
             lca=path_x[i];
         }
         else break;
     }
     cout<<lca;

     return 0;
}
