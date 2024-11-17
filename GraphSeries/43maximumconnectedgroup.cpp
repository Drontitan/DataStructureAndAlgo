#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// https://www.geeksforgeeks.org/problems/maximum-connected-group/1
class Disjoint{
    public:
  vector<int>parent,rank,size;
  Disjoint (int n){
      parent.resize(n+1,0);
      rank.resize(n+1,0);
      size.resize(n+1,0);
      for(int i=0;i<=n ;i++){
          rank[i]=0;
          parent[i]=i;
          size[i]=1;
      }
  }
  
  int findparent(int node){
      if(node==parent[node])return node;
      return parent[node] = findparent(parent[node]);
  }
  

  
  void UnionBysize(int u , int v){
      int ulu = findparent(u);
      int ulv = findparent(v);
      if(ulu==ulv)return ;
      
      if(size[ulu]<size[ulv]){
          parent[ulu]=ulv;
          size[ulv]+=size[ulu];
      }
      else{
          parent[ulv]=ulu;
          size[ulu]+=size[ulv];
      }
  }
    
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        Disjoint ds(n*m);
        // rown 1st step we have colorowned all the 1 to there parent 
        for(int row=0; row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col]==0)continue;
                
                int drow[]= {-1,0,1,0};
                int dcol[] ={0,1,-1,0};
                for(int k =0;k<4;k++){
                    int nrow = row + drow[k];
                    int ncol = col+dcol[k];
                    
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&grid[nrow][ncol]==1){
                        int node = row*m+col;
                        int adcolnode= nrow*m+ncol;
                        ds.UnionBysize(node,adcolnode);
                    }
                }
            }
        }
        
        int maxa=0;
        // step 2;
        // we converted 0 to 1 and then counted rowt maxrowmum size of components;
        for(int row=0; row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col]==1)continue;
                set<int>component;
                int drow[]= {-1,0,1,0};
                int dcol[] ={0,1,-1,0};
                for(int k =0;k<4;k++){
                    int nrow = row + drow[k];
                    int ncol = col+dcol[k];
                    
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&grid[nrow][ncol]==1){
                        int node = nrow*m+ncol; // here rowt rows the cell node 
                       component.insert(ds.findparent(node));
                    }
                }
                
                int sizetotal=0;
                for(auto ele :component){
                    sizetotal+=ds.size[ele];
                }
                maxa=max(maxa,sizetotal+1);
            }
        }
        // the whole matrrowx can be of 1 then we have to also check 
        for(int cellno =0; cellno<n*m;cellno++){ // here because we have node as cell no
            maxa=max(maxa,ds.size[ds.findparent(cellno)]);
        }
        
        return maxa; 
        
    }
};


int main(){
    
    return 0;
}