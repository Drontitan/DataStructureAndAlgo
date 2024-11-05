#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here the terminal nodes are called that which have only incoming node and not outgoing node 
// the node which are connected to these nodes are called as safe node 

// The node which is in cycle and node which are link to the cycle are not safe node apart from these
// all are safe node 
 

// TC- O(N +2E)
//SC- O(n)+O(N)+O(N);

bool dfscycle(int node , vector<int>vec[],int visi[] ,int path[],int check[]){
    visi[node]=1;
    path[node]=1;
    check[node]=0;
    for(auto ele : vec[node]){
         if(visi[ele]==0){
            if(dfscycle(ele,vec,visi,path,check)==true){
                check[node]=0;
                return true;}
            
        }
        else if (path[ele]){
            check[node]=0;
            return true;
        }  //if its is path visited then we will return true 
    }
    check[node]=1;
    path[node]=0;
    return false;
}


int main(){
    int n,e;
    cin>>n>>e;

    vector<int>vec[n+1];
    int visi[n+1]={0};
    int path[n+1]={0};
    int check[n+1]={0};
    vector<int>ans;
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
    }

    bool flag=false;
    for(int i =0 ;i <n; i++){
        if(visi[i]==0){
         dfscycle(i,vec,visi,path,check);
    }
    }
     for(int i=0; i<n; i++){
        if(check[i])ans.push_back(i);
     }
     for(auto ele:ans)cout<<ele<<" ";

    return 0;
}