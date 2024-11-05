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

class solution {
   vector<int>numberofisland(int n , int m , vector<vector<int>>&operators){
      DisjoinSet ds(n*m);
      vector<vector<int>>visi(n,vector<int>(m,0));
      int count=0;
      vector<int>ans;
      
      for(auto ele:operators){
        int row = ele[0];
        int col = ele[1];
        if(visi[row][col]){
            ans.push_back(count); // as there will be no change in the query
            continue;
        }
        visi[row][col]=1;
        count++;
        int drow[] = {-1,0,1,0};
        int dcol[] ={0,1,0,-1};
        for(int i=0;i <4;i++){
            int nrow = row +drow[i];
            int ncol = col+ dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                if(visi[nrow][ncol]==1){
                    int nodenum = row*m+col;
                    int adjnodenum = nrow*m+ncol;
                  if(ds.findParent(nodenum)!=ds.findParent(adjnodenum)){
                    count--;
                    ds.unionBySize(nodenum,adjnodenum);
                  }
                }
            }
        }
            ans.push_back(count);
      }

      return ans;
   }


};
int main(){
   
    return 0;
}