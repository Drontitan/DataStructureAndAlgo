// a tree which have n nodes and n-1 edges and all nodes are reachable from each other 

// if we draw a mst from the graph then the sum of all the edges weight should be minimum


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Tc - O(ElogE)  
// Sc - O(E)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>visi(V,0);
        int sum=0;
        
        // see here i we need the mst store the parent as extra pair pair<int,pair<int,int>
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>q;
        // q.push({0,{0,-1}});// weight,{node , parent}
        q.push({0,0});//{ weight node }
        while(!q.empty()){
            int w = q.top().first;
            int node = q.top().second;
            q.pop();
            if(visi[node]==1)continue;
            visi[node]=1;// this is where we add to the mst 
            sum+=w;
            for(auto ele :adj[node]){
                int adjnode=ele[0];
                int adw = ele[1];
                q.push({adw,adjnode});
            }
        }
        
        return sum;
    }
int main(){
    
    return 0;
}
// to print the mst 

// int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
//         greater<pair<int,pair<int,int>>>>q;
        
//         q.push({0,{0,-1}}); // wieght , node, parent // this used when we havee to print
//         // the mst here if we dont have to print just print the sum then dont use it 
        
//         vector<int>visi(V,0);
//         int sum =0;
//         vector<pair<int,int>>mst;
//         while(!q.empty()){
//             int w  = q.top().first;
//             int node = q.top().second.first;
//             int parent = q.top().second.second;
//             q.pop();
//             if(visi[node])continue;
//             visi[node]=1;
//             sum+=w;
            
//             if(parent!=-1)mst.push_back({parent,node});
//             for(auto ele:adj[node]){
//                 q.push({ele[1],{ele[0],node}});
//             }
//         }
        
//         // for(auto ele:mst)cout<<ele.first<<" "<<ele.second<<endl;
//         return sum;
//     }