#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printallpaths(vector<vector<int>>&vec,string str,int row,int col){
  
     
    if(row==vec.size()-1 && col==vec[0].size()-1){
        cout<<str;
        cout<<endl;
        return;
    }
    if(vec[row][col]==0)return;
    vec[row][col]=0;
    if(row<vec.size()-1){
        printallpaths(vec,str+'D',row+1,col);
        
    }
    if(row>0){
        printallpaths(vec,str+'U',row-1,col);
  
    }
    if(col<vec[0].size()-1){
        printallpaths(vec,str+'R',row,col+1);
      
    }
    if(col>0){
        printallpaths(vec,str+'L',row,col-1);
       
    }
     vec[row][col]=1;
}
int main(){
    vector<vector<int>>board={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    printallpaths(board,"",0,0);
    return 0;
}