#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs(queue<int>&q,int node ,set<int>&visited,map<int,vector<pair<int,int>>>&G ){
    long long count=0;
    q.push(node);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for(auto n:G) {
               for(auto ele : n.second){
            if(visited.count(ele.first) == 0) {
                q.push(ele.first);
                if(ele.second==0)count++;
                
                visited.insert(ele.first);
            }
        }
        }
    }

}

int main(){
    int n,k;
    cin>> n;
    cin>>k;
      map<int,vector<pair<int,int>>>mp ;  
      set<int>visited;
      for(int i=0 ;i<n-1;++i){
         int a,b,wt;
         cin>>a>>b>>wt;
         mp[a].push_back({b,wt});// if it is directed  witht the weight
         mp[b].push_back({a,wt});  // if it is undirected    with weight 
      }

    //   for(auto node :mp){
    //       cout<<node.first<<": ";
    //       for(auto ajdacentnode : node.second){
    //           cout<<ajdacentnode.first<<" ";  // with the weight to print along with it 
    //           cout<<ajdacentnode.second<<" ";
    //       }
    //       cout<<endl;
    //   }

    queue<int>q;
    visited.insert(1);
    bfs(q,1,visited,mp);
    return 0;
}