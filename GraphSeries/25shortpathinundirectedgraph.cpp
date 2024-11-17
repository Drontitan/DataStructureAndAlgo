#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>>vec(N);
        for(int i =0; i<M; i++){
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dis(N,1e9);
        queue<int>q;
        q.push(src);
        dis[src]=0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            if(dis[node]!=1e9){
            for(auto ele:vec[node]){
                if(dis[node]+1<dis[ele]){
                    dis[ele]=1+dis[node];
                    q.push(ele);
                }
            }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dis[i]==1e9)dis[i]=-1;
        }
        
        return dis;
}
