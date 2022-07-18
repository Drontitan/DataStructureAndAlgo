#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

//TC-O(N) SC-O(N);
vector<int>bottomview(Treenode *root){
    vector<int>ans;
    map<int,int>mp;
    queue<pair<Treenode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Treenode *node =it.first;
        int x=it.second;
        mp[x]=node->val;// here we have done all the thing same as we done before the change was that 
        // we have just replace the previously inserted values
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }

    for(auto ele:mp){
        ans.push_back(ele.second);
    }
    return ans;
}

// do not the recursive traversal 

int main(){
    
    return 0;
}