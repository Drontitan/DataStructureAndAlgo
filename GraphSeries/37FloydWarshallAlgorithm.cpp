// it is a multiple source shortest path algorithm
// help u detect negative cycle as well

// intitution : -  try out every different vertice to reach the source node 
// here it make use of dp because we are using something which is already precomputed 
// we will be using here adjacency matrix here store the cost of going from 1 node to other 


// here we will keep row and column for that source as is it because it will be better for that 
// source to reach itself;


// from every node we will get shortest distance to every other node 
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    // Tc O(n^3)
	    int n = matrix.size();
	    
	    for(int i=0; i< n;i++){
	        for(int j=0; j< n; j++){
	            if(matrix[i][j]==-1)matrix[i][j]=1e9;
	            if(i==j)matrix[i][j]==0;
	        }
	    }
	    for(int k =0; k <n;k++){
	    for(int i=0; i< n;i++){
	        for(int j=0; j< n; j++){
	            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]); // we are trying the to reach
                // that via different source 
	        }
	    }
	    }

        // if there is an negative cycle
        // for(int i=0;i<n ;i++){
        //     if(matrix[i][i]<0)return -1;
        // }
	    
	    for(int i=0; i< n;i++){
	        for(int j=0; j< n; j++){
	            if(matrix[i][j]==1e9)matrix[i][j]=-1;
	        }
	    }
	}

int main(){
    
    return 0;
}