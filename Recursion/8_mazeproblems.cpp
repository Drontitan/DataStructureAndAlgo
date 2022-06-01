#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int count(int r,int c){
      
     if(r==1 || c==1){
         return 1;
     }
     int left = count(r-1,c);
     int right =count(c-1,r);

     return left+right;
}
void path(string p,int r,int c){
    if(r==1&&c==1){
        cout<<p<<endl;
        return;
    }
     if(r>1){
         path(p+"D",r-1,c);
     }
     if(c>1){
         path(p+"R",r,c-1);
     }
     
}
void diagonalpath(string p,int r,int c){
    if(r==1&&c==1){
        cout<<p<<endl;
        return;
    }
    if (r > 1 && c > 1)
    {
        diagonalpath(p + "D", r - 1, c - 1);
    }
     if(r>1){
         diagonalpath(p + "V", r - 1, c);
     }
  
     if(c>1){
         diagonalpath(p + "H", r, c - 1);
     }
     
}
void obstacelpath(string p,vector<vector<bool>>&arr,int r,int c){

    if (r ==arr.size()-1 && c ==arr[0].size()-1)
    {
        cout<<p<<endl;
        return;
    }
     if(!arr[r][c]){
        return;
     }
     if (r<arr.size() - 1)
     {
         obstacelpath(p + "D",arr, r+1, c);
     }
     if (c<arr[0].size() - 1)
     {
         obstacelpath(p + "R",arr, r, c+1);
     }
}
void allpath(string p,vector<vector<bool>>&arr,int r,int c)// backtracking problem 
{ 

    if (r ==arr.size()-1 && c ==arr[0].size()-1)
    {
        cout<<p<<endl;
        return;
    }
    if (!arr[r][c])
    {
        return;
    }
      // i am considering this an block in my path
    arr[r][c]=false;


     if (r<arr.size() - 1)
     {
         allpath(p + "D", arr, r + 1, c);
     }
     if (c<arr[0].size() - 1)
     {
         allpath(p + "R", arr, r, c + 1);
     }
     if (r>0)
     {
         allpath(p + "U", arr, r-1, c);
     }
     if (c>0)
     {
         allpath(p + "L", arr, r, c-1);
     }
     // this line is where the function get over
     // so beforet the function is removed the changes that were made by that function
     arr[r][c] = true;
}

void mazeallpathsprint(string ans, int row, int col, vector<vector<bool>> maze, vector<vector<int>> path, int step)
{
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        path[row][col] = step;
        for (int i = 0; i < path.size(); i++)
        {
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << path[i][j] << ' ';
            }
            cout << endl;
        }
        cout << ans << endl;
        return;
    }
    if (maze[row][col] == false)
        return;
    maze[row][col] = false;
    path[row][col] = step;
    if (row < maze.size() - 1)
    {
        mazeallpathsprint(ans + 'D', row + 1, col, maze, path, step + 1);
    }
    if (col < maze[0].size() - 1)
    {
        mazeallpathsprint(ans + 'R', row, col + 1, maze, path, step + 1);
    }
    // It cant go out of bound
    if (row > 0)
    {
        mazeallpathsprint(ans + 'U', row - 1, col, maze, path, step + 1);
    }
    // It cant go out of bound
    if (col > 0)
    {
        mazeallpathsprint(ans + 'L', row, col - 1, maze, path, step + 1);
    }
    // Backtracking Bolte
    // Mark the cells which the function has visited as they were before
    maze[row][col] = true;
    path[row][col] = 0;
}
int main(){
     int r,c;
    //  cout<<count(3,3);
    //  path("",3,3);
    //  diagonalpath("",3,3);

    //   vector<vector<bool>>vec={{true,true,true},{true,false,true},{true,true,true}};

      vector<vector<bool>>vec={{true,true,true},{true,true,true},{true,true,true}};
      vector<vector<int>> path = {
          {0, 0, 0},
          {0, 0, 0},
          {0, 0, 0},
      };
      mazeallpathsprint("", 0, 0,vec, path, 1);
      return 0;
}