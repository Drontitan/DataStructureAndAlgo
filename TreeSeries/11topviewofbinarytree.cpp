#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//TC-O(N) SC-O(N);

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

// we will be taking same as we have done before but this time we will be taking only vertical lines
// not the horizontal in   map<vertical,nodes>   queue<node,vertcal>.

vector<int>topview(Treenode *root){
    vector<int>ans;
    map<int,int>mp;
    queue<pair<Treenode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Treenode *node =it.first;
        int x=it.second;
        if(mp.find(x)==mp.end())mp[x]=node->val;
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }

    for(auto ele:mp){
        ans.push_back(ele.second);
    }
    return ans;
}
// we do not solve it by the recursive approach bcz we travel all the node and end with node having 
// level vertical level that cant be it vertical level it can be the vertical level of the 
// element which can be found by the level order traversal  

int main(){
    
    return 0;
}