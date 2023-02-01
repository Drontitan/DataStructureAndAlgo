#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// we have to find the terminal edges first and edges which are safe 
// 

// so we will first reverse the edges and then the node having the indegree 0 will the safe node and we will 
//start from that then will moving to the  paths we will be reducinfg the indegree of the node which are 
// connected to the safe nodes
    

//Tc-O(V+E);
//SC- O(N) 
int main(){
 
    int n,e;
    cin>>n>>e;
    
   vector<int>vec[n+1];
   int indegree[n]={0};

   for(int i=0 ;i <e; i++){
      int u, v;
      cin>>u>>v;
      vec[u].push_back(v);
   }

   vector<int>newvec[n+1];  // we are making the revese graph onver here 
   for(int i=0 ;i <n;i++){
    for(auto ele:vec[i]){
        newvec[ele].push_back(i);
        indegree[i]++;
    }
   }


   vector<int>safenodes;
   queue<int>q;
   for(int i= 0; i<n; i++){
      if(indegree[i]==0)q.push(i);
   }


   while(!q.empty()){
       int node =q.front();
       q.pop();
        safenodes.push_back(node);
       for(auto ele :newvec[node]){
        indegree[ele]--;
        if(indegree[ele]==0)q.push(ele);
       }
   }
     sort(safenodes.begin(),safenodes.end());
     for(auto ele:safenodes)cout<<ele<<" ";

     





    return 0;
}