#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/path-with-minimum-effort/


// here we are storing the max diff of that path in our distance array 
// 
typedef long long ll;
  //TC n*m * 4 & log(n*m) 
  // Elogv short form 
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m=  heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        
        q.push({0,{0,0}});
        
        while(!q.empty()){
            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(row==n-1 && col==m-1)return diff;
            
            for(int i=0;i <4; i++){
                int nrow = drow[i]+row;
                int ncol =  dcol[i]+col;
                
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neweffort = max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                    if(neweffort<dis[nrow][ncol]){ 
                        dis[nrow][ncol]=neweffort;
                        q.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                    
                }
            }
          }
                                   return -1;
    }
      

int main(){
    
    return 0;
}