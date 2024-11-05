#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// TC O(n+m) // stack as for each node we are traversin the M edges ;
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0
void toposort(int node, vector<pair<int,int>>vec[], int visi[],stack<int>st ){
     visi[node]=1;
      
      for(auto ele:vec[node]){
        int v=ele.first;
        if(!visi[v]){
            toposort(v,vec,visi,st);
        }

      }
     st.push(node);
}

int main(){
    
    int n, m;

    vector<pair<int,int>>adj[n+1];
    for(int i=0; i <m; i++){
       int u,v,wd;
       cin>>u>>v>>wd;
        adj[u].push_back({v,wd});
    }
    stack<int>st;
    int visi[n]={0};
  // for(int i=0 ;i <n ;i++){
  //   cout<<i<<" ";
  //   for(auto ele :adj[i]){
  //       cout<<ele.first<<" "<<ele.second<<endl;
  //   }
  // }
   
    for(int i=0 ;i <n; i++){
        if(!visi[i]){
            toposort(i,adj,visi,st);
        }
    }


    vector<int>dist(n);
    for(int i=0 ;i<n; i++)dist[i]=INT_MAX;
    dist[0]=0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto ele :adj[node]){
           int v= ele.first;
           int wt= ele.second;
           if(dist[node]+wt < dist[v]){
             dist[v] = wt+dist[node];
           }
        }
    }

    for(int  i=0 ;i <n; i++){
        cout<<i<<" "<<dist[i]<<" "<<endl;;
    }



    return 0;
}