#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// the nodes which are reachable to each other is called as strongly conneted component 
// we will reverse all the edges as if they are visiting each other then while reversing also we will
// be able to reach each other

// why we are reversing ?-  we wil not able to visit other SCC we will only able to visit current SCC

// here we have starting and finishing time 
// 1 sort all the edges according to finishing time  // we will get to know the first SCC [it will 
// first SCC node to start from ]
// 2 reverse the graph 
// 3 do a dfs

// its only applicable for direct graph 


// Tc -O(E+V) 
//SC-2*V

class solution{
	public:
	// for sorting according to finish time 
	void dfs(int node, vector<vector<int>>& adj ,vector<int>& visi, stack<int>&st ){
	    visi[node]=1;
	    for(auto ele:adj[node]){
	        if(!visi[ele])dfs(ele,adj,visi,st);
	    }
	    st.push(node);
	}
	// for counting the SCC
	void dfs2(int node, vector<vector<int>>& vec ,vector<int>& visi,vector<int>&temp){
	    visi[node]=1;
	    temp.push_back(node);
	    for(auto ele:vec[node]){
	        if(!visi[ele])dfs2(ele,vec,visi,temp);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>visi(V,0);
        
        stack<int>st;
        // here we are storing them according to the finish time 
        for(int i=0;i <V;i++){
            if(!visi[i]){
                dfs(i,adj,visi,st);
            }
        }
        
        // step2  reverse the edges
        vector<vector<int>>vec(V);
        for(int i=0;i<V;i++){
            visi[i]=0;
            for(auto ele:adj[i]){
                vec[ele].push_back(i);
            }
        }
        
        // we will now calulate SCC while runing dfs accros multiple components
        int scc=0;
        vector<vector<int>>ans;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visi[node]){
                vector<int>temp;
                scc++;
                dfs2(node,vec,visi,temp);
                ans.push_back(temp);
                
            }
        }
        // printing the scc
        // for(auto ele:ans){
        //     for(auto it :ele)cout<<it<<" ";
        //     cout<<endl;
        // }
        
        return scc;
        
        
    }
};

int main(){
    
    return 0;
}