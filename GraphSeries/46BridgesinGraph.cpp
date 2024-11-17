// if the remove the edge then it break in to two or more component 


// it is an undirected graph 
//1 here we find the time of inesertion  :- in which step are u reaching the node 
// 2 lowest time of insertion -  it find lowest of all apart from parent

// here we are trying to minimise the current lowest insertion and if we not able to reach that via 
// any route we are making them as bridge 

// https://www.youtube.com/watch?v=qrAub5z8FeA&ab_channel=takeUforward


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    
    int timer=1;
    
    void dfs(int node , int parent , vector<vector<int>>&vec,vector<int>&tin,vector<int>&low,
vector<int>&visi ,vector<vector<int>>&bridges){
        visi[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto ele:vec[node]){  
            if(ele==parent)continue;
            if(!visi[ele]){
                dfs(ele,node,vec,tin,low,visi,bridges);
                low[node]=min(low[node],low[ele]);
                
                // for marking it as bridge
                
                if(low[ele]>tin[node]){
                    bridges.push_back({ele,node});
                }
            }
            else{
                low[node]=min(low[node],low[ele]);
            }
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        
        vector<vector<int>>vec(n);
        
        for(auto ele:connections){
            vec[ele[0]].push_back(ele[1]);
            vec[ele[1]].push_back(ele[0]);
        }

        vector<vector<int>>bridges;
        vector<int>visi(n);
        vector<int>tin(n),low(n);
        
        dfs(0,-1,vec,tin,low,visi,bridges);
        return bridges;
        
    }
};


int main(){
    
    return 0;
}