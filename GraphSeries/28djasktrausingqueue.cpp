#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// dijkstras algorithm using priority queue [min heap]
// dijkstras cant work for negative weight 
//    -2
// o-----1
// it will go in infinite loop as 0 to 0 is distance zero and 1 to 0 is -2 as we move on forward 
// then it will go -4 -6 ans so on.. 
 

int main(){

    int n , m;
    vector<vector<pair<int,int>>>vec(n);
    for(int i=0; i<m ;i++){
        int u ,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
    }
    vector<int>dis(n,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});// take this as source node; //here the fist is weight and second i node 
    while(!q.empty()){
     auto node = q.top();
     q.pop();
     for(auto ele:vec[node.second]){ 
        if(node.first+ele.second<dis[ele.first]){
            dis[ele.first]=node.first+ele.second;
            q.push({dis[ele.first],ele.first});
        }
     }
    }

    for(int i=0;i<n; i++){
        if(dis[i]==1e9)dis[i]=-1;
    }

    for(auto ele:dis)cout<<ele<<" ";
    return 0;
}