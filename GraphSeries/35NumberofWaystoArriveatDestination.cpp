#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int countPaths(int n, vector<vector<int>>& roads) {
        // TC Elogv

        long long int mod =1e9+7;
        vector<vector<pair<long long int,long long int>>>vec(n);
        for(auto ele:roads){
            vec[ele[0]].push_back({ele[1],ele[2]});
            vec[ele[1]].push_back({ele[0],ele[2]});
        }
        vector<long long int>ways(n,0);
        vector<long long int >dist(n,1e18);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>q;
        q.push({0,0});
        while(!q.empty()){
            auto val = q.top();
            q.pop();
            long long int  dis = val.first;
            long long int node = val.second;
            
            for(auto ele:vec[node]){
                if(dis+ele.second<dist[ele.first]){
                    // the first time i  am arriving to that node 
                    dist[ele.first]=dis+ele.second;
                    q.push({dist[ele.first],ele.first});
                    ways[ele.first]=ways[node];
                }
                else if( dis+ele.second==dist[ele.first]){
                    ways[ele.first]=(ways[ele.first]+ways[node])%mod;
                }
                 
            }  
        }
         return ways[n-1]%mod;
    }
int main(){
    
    return 0;
}