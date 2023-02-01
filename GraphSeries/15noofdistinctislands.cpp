#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// here we have find the distinct pattern formed by the 1 in the given  matrix

void dfs(int row ,int col,vector<vector<int>>&visi,vector<vector<int>>&vec,vector<pair<int,int>>&res,int row0 ,int col0 ){
    visi[row][col]=1;
    res.push_back({row-row0,col-col0});
    int n=vec.size();
    int m=vec[0].size();

    int delecol[]={0,+1,0,-1};
    int delerow[]={-1,0,+1,0};

    for(int i=0 ;i<4 ;i++){
        int nrow = row+delerow[i];
        int ncol = col+delecol[i];
        if(nrow>=0  && nrow<n && ncol>=0 && ncol <m && visi[nrow][ncol]==0 && vec[nrow][ncol]==1){
            dfs(nrow,ncol,visi,vec,res,row0,col0);
        }
    }
}

int main(){
    vector<vector<int>>vec={{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};
    int n=vec.size();
    int m=vec[0].size();
     
     set<vector<pair<int,int>>>st;
     vector<vector<int>>visi(n,vector<int>(m,0));

    for(int i=0;i<n ;i++){
        for(int j= 0;j<m ;j++){
           if(!visi[i][j]  && vec[i][j]==1){
            vector<pair<int,int>>res;
            dfs(i,j,visi,vec,res,i,j);
            st.insert(res);
           }
        }
    }

    // for(auto ele :st){
    //     for(auto it :ele)cout<<it.first<<" "<<it.second<<" ";
    //     cout<<endl;
    // }



    cout<<st.size();
    return 0;
}