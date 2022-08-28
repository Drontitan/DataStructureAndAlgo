#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs(int row,int col,vector<vector<int>>&grid,int newcolor){
    
    queue<pair<int,int>>q;
    q.push({row,col});

    int n=grid.size();
    int m =grid[0].size();

    int color=grid[row][col];

    int delerow[]={-1,0,1,0};
    int delecol[]={0,1,0,-1};

    
    while(!q.empty()){
        int row=q.front().first;
        int col =q.front().second;
        q.pop();
         grid[row][col]=newcolor;
           for(int i =0 ;i<4;i++){
             int nrow= row+delerow[i];
             int ncol = col+delecol[i];
             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==color){
                q.push({nrow,ncol});
        }
        }

    }


}
void dfs(int row,int col,vector<vector<int>>&grid,int newcolor,int delerow[],int delecol[],int oricolor){
    
    int n=grid.size();
    int m =grid[0].size();

     grid[row][col]=newcolor;


        for(int i =0 ;i<4;i++){
             int nrow= row+delerow[i];
             int ncol = col+delecol[i];
             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==oricolor &&grid[nrow][ncol]!=newcolor){
                dfs(nrow,ncol,grid,newcolor,delerow,delecol,oricolor);
        }
    }
}

int main(){
    vector<vector<int>>grid={{1,1,1},{2,2,0},{2,2,2}};
     
     int n=grid.size();
     int m=grid[0].size();

     
     int row=2,col=0;
     int newcolor=3;
    int delerow[]={-1,0,1,0};
    int delecol[]={0,1,0,-1};
    int oricolor=grid[row][col];
    //  bfs(row,col,grid,newcolor);
     dfs(row,col,grid,newcolor,delerow,delecol,oricolor);
    
    for(int i=0 ;i <n ;i++){
        for(int j =0 ;j <m ;j++ ){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}