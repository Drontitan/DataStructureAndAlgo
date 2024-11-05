//dijktras using set
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){

    int n , m;
    vector<vector<pair<int,int>>>vec(n);
    for(int i=0; i<m ;i++){
        int u ,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
    }
    vector<int>dis(n,1e9);
    set<pair<int,int>>st;
    st.insert({0,0});// take this as source node; //here the fist is weight and second i node 
    while(!st.empty()){
     auto node = *st.begin();
     st.erase(node);
     for(auto ele:vec[node.second]){ 
        if(node.first+ele.second<dis[ele.first]){
            if(dis[ele.first]!=1e9){
                // erase if it is already existed
            st.erase({dis[ele.first],ele.first});
            }
            dis[ele.first]=node.first+ele.second;
            st.insert({dis[ele.first],ele.first});
        }
     }
    }

    for(int i=0;i<n; i++){
        if(dis[i]==1e9)dis[i]=-1;
    }

    for(auto ele:dis)cout<<ele<<" ";
    return 0;
}