#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void matrix(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n+1,vector<int>(n+1,0));
    
    for(int i= 0; i<m;i++){
            int a,b;
            cin>>a>>b;
            vec[a][b]=1;// hrer if we get the weight then instead of 1 we will inserting the weight
            vec[b][a]=1;
    }
    for(auto ele:vec){
        for(auto it :ele){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

void adjlist(){
    int n,m;
    cin>>n>>m;
    vector<int>vec[n+1];
    // incase of weighted graph we will storing the pair
    for(int i=0 ;i <m;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
      
    for(int i=0;i<n;i++){
       cout<<i<<":";
      for(auto ele:vec[i])cout<<ele<<" ";
       cout<<endl;
    }
}
void adjlistforweight(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>vec(m+1);
    // incase of weighted graph we will storing the pair
    for(int i=0 ;i <m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
    }
    int i=0;
     for(auto ele:vec){
      cout<<i<<":"<<" ";
      for(auto it :ele)cout<<it.first<<","<<it.second<<" ";
      cout<<endl;
      i++;
     } 
}

int main(){
 
//  matrix();
    //  adjlist();
    adjlistforweight();
    return 0;
}