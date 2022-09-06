#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// TC- O(N +2E)
//SC- O(n)+O(N)+O(N);

bool dfscycle(int node ,int parent, vector<int>vec[],int visi[] ,int path[]){
    visi[node]=1;
    path[node]=1;
    for(auto ele : vec[node]){
         if(visi[ele]==0){
            if(dfscycle(ele,node,vec,visi,path)==true)return true;
            
        }
        else if (path[ele])return true;  //if its is path visited then we will return true 
    }
    path[node]=0;
    return false;
}


int main(){
    int n,e;
    cin>>n>>e;

    vector<int>vec[n+1];
    int visi[n+1]={0};
    int path[n+1]={0};
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
    }

    bool flag=false;
    for(int i =1 ;i <=n; i++){
        if(visi[i]==0){
         if(dfscycle(i,-1,vec,visi,path)==true){
            flag=true;
            break;
         }
    }
    }
    if(flag)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}