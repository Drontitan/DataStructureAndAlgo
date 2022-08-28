#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//SC-O(N^2) +O(N^2);
//TC- O(N^2)+O(N^2)*8

// you want to find the number of the islands in the matrix 

void bfs(int row, int col , vector<vector<int>>&visi,vector<vector<int>>grid){

    visi[row][col]=1; 
    queue<pair<int,int>>q;
    q.push({row,col});
    
    int n=grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row =q.front().first;
        int col = q.front().second;
        q.pop();
        for(int delerow=-1; delerow<=1;delerow++){
            for(int delecol=-1; delecol<=1;delecol++){
             int nrow= row+delerow;
             int ncol = col+delecol;

             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visi[nrow][ncol]){
                q.push({nrow,ncol});
                visi[nrow][ncol]=1;
             }
        }
        }
    }


}

int main(){
    
    vector<vector<int>>grid={{0,1,1,0},{0,1,1,0},{0,0,0,0},{1,0,0,1},{1,1,1,1}};

    int n=grid.size();
    int m= grid[0].size();
    
    vector<vector<int>>visi(n,vector<int>(m,0));
   
   int count=0;
    for(int i=0 ;i <n;i++){
        for(int j=0; j<m; j++){
            if(!visi[i][j] && grid[i][j]==1){
            count++;
             bfs(i,j,visi,grid);
            }
        }
    }

    cout<<count<<" ";

    return 0;
}