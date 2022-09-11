#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// if there is the link like a comes before b b comes befoe c like this then we have to find the order 

// we will first find the indgree of all the nodes the the nodes having the indgree as 0 will be pushed
// in to the queue then rest of the indegree interconted to the number will be reduce slowly 
// and at last we will be getting the topo sort of the nodes 

//Tc-O(V+E);
//SC- O(N) 
int main(){
    int n,e;
    cin>>n>>e;
   vector<int>vec[n+1];
   int indegree[n]={0};

   for(int i=0 ;i <e;i ++){
    int u, v;
    cin>>u>>v;
    vec[u].push_back(v);
   }




   for(int i=0 ; i<n; i++){ 
    for(auto ele:vec[i]){
       indegree[ele]++;
    }
   }

//    for(int i=0;i<n; i++)cout<<i<<" "<<indegree[i]<<endl;

   queue<int>q;
   for(int i= 0; i<n; i++){
      if(indegree[i]==0)q.push(i);
   }

   vector<int>topo;
   while(!q.empty()){
       int node =q.front();
       q.pop();
       topo.push_back(node);
       // node is in your topo sort so pls remove it from the queue 
       for(auto ele :vec[node]){
        indegree[ele]--;
        if(indegree[ele]==0)q.push(ele);
       }
   }

   for(auto ele :topo)cout<<ele<<" ";



    return 0;
}