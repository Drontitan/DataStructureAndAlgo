#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
typedef long long ll;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(auto ele:edges){
            mat[ele[0]][ele[1]]=ele[2];
            mat[ele[1]][ele[0]]=ele[2];
        }
        
        for(int i=0; i<n;i++)mat[i][i]=0;
        
        for(int k =0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0 ;j <n ;j++){
                    if(mat[i][k]==1e9 || mat[k][j]==1e9)continue;
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        
        int city=-1,countmax=n+1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=countmax){
                countmax=count;
                city=i;
            }
        }
        
        return city;
    }

int main(){
    
    return 0;
}