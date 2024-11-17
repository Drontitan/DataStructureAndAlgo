#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// here it is modifired dijktras as we are storing min dis first we are storing the  stops 
// because we want to check the stops first then distance and here queue is used because 
// we are doing +1 ,+2 like in bfs that why we used queue here 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>vec(n);
       queue<pair<int,pair<int,int>>>q;
        // TC E - >edges - >flights.size(); as here we dont use priority queue thats why logv not there
        
        
        for(int i=0;i<n;i++){
            for(auto ele:flights){
                vec[ele[0]].push_back({ele[1],ele[2]});
            }
        }
        vector<int>dis(n,1e9);
        dis[src]=0;
        q.push({0,{src,0}}); // here we are storing stops , {src,distance}
        
        
        while(!q.empty()){
            int cost = q.front().second.second;
            int node = q.front().second.first;
            int stops=q.front().first;
            q.pop();
            if(stops>k)continue;
        
            for(auto ele : vec[node]){
                
                if(cost+ele.second <dis[ele.first] && stops<=k){
                    dis[ele.first]=cost+ele.second;
                    q.push({stops+1,{ele.first,dis[ele.first]}});
                }
                
            }
        }
                
                
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
int main(){
    
    return 0;
}