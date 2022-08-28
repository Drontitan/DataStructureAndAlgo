#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// find the graph contains the cycle or not  : - it for the both connected and non connected components 
// we will just the run the for  loop for the detection if it is not visited then it will go else it will not go 
// for that 

//TC- O(N +2E)
// SC-O(N) +O(N)
bool detectcycle(int src , vector<int>vec[],int visi[]){
    visi[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node =q.front().first;
        int parent =q.front().second;
        q.pop();
        for(auto ele: vec[node]){
          if(!visi[ele]){
            q.push({ele,node});
            visi[ele]=1;
            }
            else if(parent!=ele)return true; // main part where the we detect the cycle 
            // if it is visited and the ele is not the parent 
        }
    }
    return false;
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<int>vec[n+1];
    int visi[n+1]={0};

    for(int i=1 ;i<=e;i++){
       int u,v;
       cin>>u>>v;
       vec[u].push_back(v);
       vec[v].push_back(u);
    }
    
    bool flag=false;
    for(int i=1 ;i <=n;i++){
        if(!visi[i]){
            if(detectcycle(i,vec,visi)){
                flag=true;
                break;
            }
        }
    }
    
    if(flag)cout<<"true"<<endl;
    else cout<<"false"<<endl;
    
    return 0;
}