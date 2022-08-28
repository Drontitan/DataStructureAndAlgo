#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// TC- O(N +2E)
//SC- O(n)+O(N)+O(N);

bool dfscycle(int node ,int parent, vector<int>vec[],int visi[]){
    visi[node]=1;
    for(auto ele : vec[node]){
         if(!visi[ele]){
            if(dfscycle(ele,node,vec,visi)==true)return true;
            
        }
        else if (ele!=parent)return true;
    }
    return false;
}


int main(){
    int n,e;
    cin>>n>>e;

    vector<int>vec[n+1];
    int visi[n+1]={0};
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    bool flag=false;
    for(int i =1 ;i <=n; i++){
        if(!visi[i]){
         if(dfscycle(i,-1,vec,visi)==true){
            flag=true;
            break;
         }
    }
    }
    if(flag)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}