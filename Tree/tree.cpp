#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, map<int, vector<int>>& G, set<int>& visited) {
    visited.insert(node);
    cout << node << " ";
    for(int neighbour: G[node]) {
        
        if(visited.count(neighbour) == 0) {

            dfs(neighbour, G, visited);
        }
    }
}



void bfs(queue<int>&q,int node ,set<int>&visited,map<int,vector<int>>&G){
    q.push(node);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for(int n: G[node]) {

            if(visited.count(n) == 0) {
                q.push(n);
                visited.insert(n);
            }
        }
    }

}

int main(){
    int n;
    cin >> n;

      map<int,vector<int>>mp;
    //   map<int,vector<pair<int,int>>>mp;//  with the weight   
      set<int>visited;
      for(int i=0 ;i<n;i++){
         int a,b,wt;
         cin>>a>>b;
        //  cin>>a>>b>>wt;
        //  mp[a].push_back({b,wt});// if it is directed  witht the weight
        //  mp[b].push_back({a,wt});  // if it is undirected    with weight 
         mp[a].push_back(b);// if it is directed
         mp[b].push_back(a);  // if it is undirected 

      }

    //   for(auto node :mp){
    //       cout<<node.first<<": ";
    //       for(auto ajdacentnode : node.second){
    //           cout<<ajdacentnode.first<<" ";  // with the weight to print along with it 
    //           cout<<ajdacentnode.second<<" ";
    //       }
    //       cout<<endl;
    //   }
      for(auto node :mp){
          cout<<node.first<<": ";
          for(auto ajdacentnode : node.second){
              cout<<ajdacentnode<<" ";
              cout<<ajdacentnode<<" ";
          }
          cout<<endl;
      }

    // dfs(1,mp,visited);
    // queue<int>q;
    // visited.insert(1);
    // bfs(q,1,visited,mp);
    return 0;
}