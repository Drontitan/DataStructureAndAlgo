// will only work if given an directed graph 
// if given undirected graph then convert it in to direct graph with weight
// it also works for negative weight

// relax all the edges n-1 time sequentially
// relax dist[u]+wt <dist[v] dist[v]=dist[u]+wt


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Tc V*E  so implement when we are given negative weight 
 vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
            vector<int>dist(V,1e8);
            dist[S]=0;
            for(int i=0; i<V-1;i++){ //  v-1 because we will have one that we have already reached 
            // it will help us in every step to get back n-1 
                for(auto ele:edges){
                    int u = ele[0];
                    int v= ele[1];
                    int wt = ele[2];
                    if(dist[u]!=1e8 &&  dist[u]+wt <dist[v]){
                        dist[v]=dist[u]+wt;
                    }
                }
            }
            // nth relaxation to check the negative cycle; // see if we are reducing it after already
            // there then there is negative cycle 
            for(auto ele:edges){
                    int u = ele[0];
                    int v= ele[1];
                    int wt = ele[2];
                    if(dist[u]!=1e8 &&  dist[u]+wt <dist[v]){
                       return {-1};
                    }
            }
            return dist;
    }
int main(){
    
    return 0;
}