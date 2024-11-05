#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DisjoinSet{
    vector<int>rank,parent,size;
    public:
    DisjoinSet(int n){
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      size.resize(n+1,0);
        for(int i=0;i <=n ;i++){
             rank[i]=0;
             parent[i]=i;
             size[i]=1;
        }
    }

    int findParent(int node ){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findParent(parent[node]); // path compression here 
    }

    void unionByRank(int u, int v){
        int ulp_u= findParent(u);
        int ulp_v= findParent(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if (rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u= findParent(u);
        int ulp_v= findParent(v);
        if(ulp_u==ulp_v)return;
         if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


int main(){
    DisjoinSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    // if 3 and 7 belong to the same component or not 
        cout<<ds.findParent(3)<<" "<<ds.findParent(7)<<endl;
    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"same"<<"\n";
    }
    else cout<<"not same"<<endl;

    // after adding this node 
    // ds.unionByRank(3,7);
    ds.unionBySize(3,7);

        cout<<ds.findParent(3)<<" "<<ds.findParent(7)<<endl;
    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"sameafter"<<endl;
    }
    else cout<<"not sameafter"<<endl;
    return 0;
}