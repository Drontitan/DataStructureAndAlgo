#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// from each cell we have to find the distance of each cell that is containing having the 1 


int main(){

    vector<vector<int>>vec={{0,0,0},{0,1,0},{1,0,1}};
    int n=vec.size();
    int m=vec[0].size();
    
    vector<vector<int>>visi(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,0));
    
    queue<pair<pair<int,int>,int>>q;
    //TC-O(N*M) 
    for(int i=0 ;i <n ;i++){
        for(int j=0 ;j<m ;j++){
            if(vec[i][j]==1){
                q.push({{i,j},0});
                visi[i][j]=1;
            }
            else{
                visi[i][j]=0;
            }
        }
    }

    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};

    //TC- O(N*M) *4
    while(!q.empty()){
        int r=q.front().first.first;
        int c= q.front().first.second;
        int step =q.front().second;
        dis[r][c]=step;
        q.pop();
        for(int i=0 ;i <4;i++){
            int nrow = r+delrow[i];
            int ncol =c+delcol[i];
            if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && visi[nrow][ncol]==0){
                q.push({{nrow,ncol},step+1});
                visi[nrow][ncol]=1;
            }
        }
    }
    for(auto ele:dis){
        for(auto it :ele)cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}