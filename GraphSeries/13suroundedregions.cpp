#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// convert all the zeros to one if there are surrounded by  all the ones means they are not connected to that zero
// who start from the zero that lie on the boundary 

//TC- O(N*M *4)+O(N*M)
//SC-(N*M)

 
void dfs(int row, int col,vector<vector<int>>&visi,vector<vector<int>>&vec){
    visi[row][col]=1;

    int delecol[]={0,+1,0,-1};
    int delerow[]={-1,0,+1,0};

    int n=vec.size();
    int m=vec[0].size();

    for(int i=0 ;i<4;i++){
      int nrow = delerow[i]+row;
      int ncol = delecol[i]+col;
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0 && vec[nrow][ncol]==0){
        dfs(nrow,ncol,visi,vec);
      }
    }

}

int main(){
    vector<vector<int>>vec={{1,1,1,1,1},{1,0,0,1,0},{1,1,0,1,0},{1,0,1,0,1},{0,0,1,1,1}};
    int n=vec.size();
    int m=vec[0].size();

    vector<vector<int>>visi(n,vector<int>(m,0));
     
     for(int j=0;j<m;j++){
        // first row
       if(!visi[0][j]  && vec[0][j]==0){
        dfs(0,j,visi,vec);
       }

       //last row
       if(!visi[n-1][j] && vec[n-1][j]==0){
         dfs(n-1,j,visi,vec);
       }
     } 
     for(int j=0;j<n;j++){
        // first column
       if(!visi[j][0]  && vec[j][0]==0){
        dfs(j,0,visi,vec);
       }

       //last  column
       if(!visi[j][m-1] && vec[j][m-1]==0){
         dfs(j,m-1,visi,vec);
       }
     } 

     for(int i=0 ;i<n; i++){
        for(int j =0;j<m ;j++){
            if(visi[i][j]==0 && vec[i][j]==0)vec[i][j]=1;
        }
     }

     for(auto ele :vec){
        for(auto it :ele)cout<<it<<" ";
        cout<<endl;
     }

      

    return 0;
}