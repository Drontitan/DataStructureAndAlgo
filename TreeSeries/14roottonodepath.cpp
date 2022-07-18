#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

// find the path from the node to the root and make sure that node!= root  

// here will be doing the inorder traversal 

///we will be going left then right if it is leaf node then it will remove the element we have 
// while   traversing through the nodes and our call will be return 

bool getpath(Treenode *root,int x,vector<int>&vec){
    if(root==NULL)return false;

    vec.push_back(root->val);

    if(root->val==x)return true;
    
    return getpath(root->left,x,vec)||getpath(root->right,x,vec);

    vec.pop_back();
    return false;
}

vector<int>solve(Treenode *root,int B){
    vector<int>vec;
    if(root==NULL)return vec;
    getpath(root,B,vec);
    return vec;
}

int main(){
    
    return 0;
}