#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
         int n = grid.size();
         int m = grid[0].size();
         if(source==destination){
            return 0;
        }
         queue<pair<int,pair<int,int>>>q;
         q.push({0,{source.first,source.second}});
          vector<vector<int>>dis(n,vector<int>(m,1e9));
          dis[source.first][source.second]=0;
          int drow[]={-1,0,1,0};
          int dcol[]={0,1,0,-1};
         while(!q.empty()){
             auto it = q.front();
             int dist = it.first;
             int row= it.second.first;
             int col = it.second.second;
             q.pop();
             for(int i=0; i<4;i++){
                 int nrow = row+ drow[i];
                 int ncol = col+dcol[i];
                 if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && 
                dis[nrow][ncol]>1+dist ){
                      dis[nrow][ncol]=1+dist ;
                      if(nrow==destination.first && ncol==destination.second)return dist+1;
                     q.push({1+dist,{nrow,ncol}});
                 }
             }
         }
         
         return -1;
    }
int main(){
    
    return 0;
}