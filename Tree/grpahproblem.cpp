#include <bits/stdc++.h>
using namespace std;

//Leetcode Flood Fill

//  to solve number of islands 


void dfs(int i,int j ,int initialcolor,int newcolor, vector<vector<int>>&image) {
    int n= image.size();
    int m =image[0].size();
      if(i<0 || j<0)return;
      if(i>=n || j>=m)return;
      if(image[i][j]!=initialcolor)return;
      image[i][j]=newcolor;
     dfs(i+1,j,initialcolor,newcolor,image);
     dfs(i-1,j,initialcolor,newcolor,image);
     dfs(i,j-1,initialcolor,newcolor,image);
     dfs(i,j+1,initialcolor,newcolor,image);
}
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     int initialcolor= image[sr][sc];
     if(initialcolor!=newColor)
        dfs( sr, sc ,initialcolor, newColor, image);

    return image;
 }
int main() {
    int N,e;
    cin >>N>>e;
    vector<vector<int>>G(N+1);

    for(int i = 0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
     


    return 0;
}
