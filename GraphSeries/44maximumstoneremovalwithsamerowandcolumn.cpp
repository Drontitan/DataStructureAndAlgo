#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// see video if u didnt get https://www.youtube.com/watch?v=OwMNX8SPavM&ab_channel=takeUforward
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
    int removeStones(vector<vector<int>>& stones) {
        
        int maxrow =0,maxcol=0;
        
        for(int i=0;i<stones.size();i++){
            maxrow=max(maxrow,stones[i][0]);
            maxcol=max(maxcol,stones[i][1]);
        }
        
        Disjoint ds(maxrow+maxcol+1);
        
        unordered_map<int,int>stonenode;
        
        for(auto ele:stones){
          int noderow =ele[0];
          int nodecol =ele[1]+maxrow+1;
            // here we are making the nodes diff like for row 
        // 0 1 2 3 4 and for column row +col+1 so the number should be diff 
        // 5 6 7 8 like this 
            
            // here we have make them as a seperate node and late on gone combining them 
          ds.UnionBysize(noderow,nodecol);
          stonenode[noderow]=1; // here we are marking the nodes so we can check further for ultimate parent
          stonenode[nodecol]=1;
        }
        
        int count=0;
        for(auto ele:stonenode){
            if(ds.findparent(ele.first)==ele.first){ // here we are finding the ulitmate
// parent 
                count++;
            }
        }
        // ultimate parent are those to which all the other node are connected and can be removed 
        return stones.size()-count; // subtracting the ultimate parent 
    }
};
int main(){
    
    return 0;
}