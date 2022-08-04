#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int findmaxarea(vector<int>&vec){
      stack<int>st;
      int maxa =0; 
      int n= vec.size();
     for(int i= 0; i<=n ;i++){
     while(!st.empty() && (i==n || vec[st.top()]>=vec[i])){
        int heig = vec[st.top()];
        st.pop();
        int weidth;
        if(st.empty())weidth=i;
        else weidth = i - st.top() -1;
        maxa = max(maxa, weidth *heig);
     }
     st.push(i);
    }

    return maxa;
}

int main(){
     vector<vector<int>>mat= {{1,0,1,1},{1,0,1,1},{0,1,0,1},{1,1,1,1},{0,0,0,1}};
    int n= mat.size();
    int m= mat[0].size();
    vector<int>height(m,0);
    int maxarea =0;

    // TC O(N * ( M+N)) 
   for (int i = 0; i < n; i++)
   {
    for (int j = 0; j < m; j++)
    {
        if(mat[i][j]==1)height[j]++;//calculating the height of the by traversing over each column 
        else height[j]=0;
    }
    int area=findmaxarea(height);
    maxarea =max(maxarea,area);
   }
   
    cout<<maxarea<<endl;
    return 0;
}