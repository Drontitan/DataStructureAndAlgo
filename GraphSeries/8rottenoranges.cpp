#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// the 0 is the no oranges 
// 1 is the fresh oranges
// 2 is the rotten oranges

// we have to rott the level wise it require the 1 unit time to rot the level wise element

// minimum require to rot all the oranges

//SC- O(N*M)
//TC- O(N*M) + O(N*M)*4

int main(){
     vector<vector<int>>vec={{0,1,2},{0,1,1},{2,1,1}};
     int n=vec.size();
     int m=vec[0].size();
     int visi[n][m];
     
     queue<pair<pair<int,int>,int>>q;
     
     
     for(int i=0 ;i <n;i++){
        for(int j =0;j<m;j++){
            if(vec[i][j]==2){
                q.push({{i,j},0});
                visi[i][j]=2;
            }
            else{
                visi[i][j]=0;
            }
        }
     }

     int time=0;
     int drow[]={-1,0,+1,0};
     int dcol[]={0,1,0,-1};
    

     while(!q.empty()){
       
       int row = q.front().first.first;
       int col = q.front().first.second;
       int t= q.front().second;
       
       time = max(time,t);
       q.pop();

        for(int i=0 ;i<4;i++){
           int nrow =row+drow[i];
           int ncol=col+dcol[i];
          if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0 && vec[nrow][ncol]==1){
            q.push({{nrow,ncol},t+1});
            visi[nrow][ncol]=2;
          }
        }
     }
    
    bool flag=false;
     for(int i=0 ;i <n;i++){
        for(int j=0;j<m;j++){
            if(visi[i][j]!=2 &&vec[i][j]==1){
                flag=true;
                break;
            }
        }
     }

     if(flag)cout<<-1<<endl;
     else cout<<time<<endl;
     



    return 0;
}