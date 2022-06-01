#include <bits/stdc++.h>
using namespace std;
const int n=1e5+10 ;

//In each query given v print the subtree of v and number of the even numbers int the subtree of v

vector<int>subtree(n);
vector<int>even_count(n);
int val[n];// if the vallue array is given 


void dfs(int vertex, vector<vector<int>>&G,int par=0) {
   // Taek action on the child before entering the vertex
   subtree[vertex]+=vertex;
   if(vertex%2==0)even_count[vertex]++;
    for(int child: G[vertex]) {
        if( child==par)continue;
       // take action on the child before entering the child node 

        dfs(child,G,vertex);
       // take action on the child after exiting the child node 
      subtree[vertex]+=subtree[child];
     even_count[vertex]+=even_count[child];
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
       for(int i = 1; i<=N; ++i) {
       cout<<subtree[i]<< " "<<even_count[i];
       cout<<endl;
    }
    // int q;
    // while(q--){
    //     int v;
    //     cin>>v;
    //     cout<<subtree[v]<< " "<<even_count[v];
    //     cout<<endl;
    
    // }

    return 0;
}
