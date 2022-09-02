#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// we have yo find the number of the 1s means the piece of land that are not connected witht the boundary 

//TC- O(N*M *4)+O(N*M)
//SC-(N*M)

 
void bfs(queue<pair<int,int>>q,vector<vector<int>>&visi,vector<vector<int>>&vec){
 

    int delecol[]={0,+1,0,-1};
    int delerow[]={-1,0,+1,0};

    int n=vec.size();
    int m=vec[0].size();

   while(!q.empty()){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for(int i=0 ;i<4;i++){
      int nrow = delerow[i]+row;
      int ncol = delecol[i]+col;
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0 && vec[nrow][ncol]==1){
        q.push({nrow,ncol});
        visi[nrow][ncol]=1;
      }
    }
    }

}

int main(){
    vector<vector<int>>vec={{0,0,0,1,1},{0,0,1,1,0},{0,1,0,0,0},{0,1,1,0,0},{0,0,0,1,1}};
    int n=vec.size();
    int m=vec[0].size();

    vector<vector<int>>visi(n,vector<int>(m,0));
    queue<pair<int,int>>q;
     
     for(int j=0;j<m;j++){
        // first row
       if(vec[0][j]==1)q.push({0,j});
       //last row
       if(vec[n-1][j]==1) q.push({n-1,j});
       
     } 
     for(int j=0;j<n;j++){
        // first column
       if(vec[j][0]==1)q.push({j,0});

       //last  column
       if(vec[j][m-1]==1)q.push({j,m-1});
     } 
    bfs(q,visi,vec);
    int count=0;


     for(int i=0 ;i<n; i++){
        for(int j =0;j<m ;j++){
            if(visi[i][j]==0 && vec[i][j]==1)count++;
        }
     }      

    cout<<count<<endl;
    return 0;
}