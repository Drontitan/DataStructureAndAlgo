#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// only for the directed acyclic graph
stack<int>st;

void dfs(vector<int>vec[],int visi[],int node,stack<int>&st){
   
   visi[node]=1;
   for(auto ele: vec[node]){
       if(!visi[ele]){
        dfs(vec,visi,ele,st);
       }
   }
   st.push(node);  // when we were going back then only we have inserted 

}

int main(){ 
      
    int n,e;
    cin>>n>>e;
     vector<int>vec[n+1];
     stack<int>st;

     int visi[n+1]={0};
     for(int i= 0;i<e; i++){
       int u,v;
       cin>>u>>v;
       vec[u].push_back(v);
     }

    for(int i=0 ;i<n; i++){
        if(visi[i]==0)dfs(vec,visi,i,st);
    }

    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    for(auto ele:topo)cout<<ele<<" ";

     
    return 0;
}