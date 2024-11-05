#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>dis(n+1,1e9);
        vector<vector<pair<int,int>>>vec(n+1);
        
        for(int i=0;i<m ;i ++){
          vec[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          vec[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        queue<pair<int,int>>q;
        dis[1]=0;
        q.push({0,1});
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
        while(!q.empty()){
            int dist = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto ele:vec[node]){
                if(dist+ele.second<dis[ele.first]){
                    dis[ele.first]=dist+ele.second;
                    q.push({dis[ele.first],ele.second});
                    parent[ele.first]=node;
                }
            }
        }

        vector<int>path;
         if(dis[n]!=1e9){
        int node =n;
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        // path.push_back(dis[n]);
        reverse(path.begin(),path.end());
        return path;
        }
        
        return {-1};
    }
int main(){
    
    return 0;
}