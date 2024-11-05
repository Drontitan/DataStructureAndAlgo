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