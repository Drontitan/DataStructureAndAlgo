#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// here we have given the prerequisite array where we were given that which operation is to be preformed when 
// then we need to apply the topological sort for the topo logical sort it should not have the cycle 
// if there is cycle we can not perform the topological algorithm 

// if we cant perform the operations the we have to return false  else true


//Tc-O(V+E);
//SC- O(N) 
int main(){
 
   vector<vector<int>>pre={{1,0},{2,1},{1,3}};
    int n,e;
    cin>>n>>e;
    
   vector<int>vec[n+1];
   int indegree[n]={0};

   for(int i=0 ;i <pre.size(); i++){
    //vec[pre[i][0]].push_back(pre[i][1]);// it is for when it given in right order 
    vec[pre[i][1]].push_back(pre[i][0]); // for the left order
   }


   for(int i=0 ; i<n; i++){ 
    for(auto ele:vec[i]){
       indegree[ele]++;
    }
   }

//    for(int i=0;i<n; i++)cout<<i<<" "<<indegree[i]<<endl;
   vector<int>topo;
   queue<int>q;
   for(int i= 0; i<n; i++){
      if(indegree[i]==0)q.push(i);
   }

  int count=0;
   while(!q.empty()){
       int node =q.front();
       q.pop();
       topo.push_back(node);
       count++;
       // node is in your topo sort so pls remove it from the queue 
       for(auto ele :vec[node]){
        indegree[ele]--;
        if(indegree[ele]==0)q.push(ele);
       }
   }

     for(auto ele: topo)cout<<ele<<" ";

     if(count==n)cout<<"true";// we are able to perform the topo sort properly 
     else cout<<"false";// we were not able to do that so the operation is not true 





    return 0;
}