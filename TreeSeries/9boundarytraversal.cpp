#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// boundary traversal :- anti clockwise
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

bool isLeaf(Treenode *root){
    if(root->left==NULL && root->right==NULL)return true;
    else return false;
}

void addleftbd(Treenode *root,vector<int>vec){

    Treenode *node =root->left;
    while(node){
        if(!isLeaf(node))vec.push_back(node->val);
        if(node->left)node=node->left;
        else node=node->right;
    }
}

void addrightbd(Treenode *root,vector<int>vec){
    Treenode *node =root->right;
    vector<int>temp;
    while(node){
        if(!isLeaf(node))temp.push_back(node->val);
        if(node->right)node=node->right;
        else node=node->left;
    }
    for(int i= temp.size()-1;i>=0;i--){
        vec.push_back(temp[i]);
    }

}


void addleaf(Treenode *root,vector<int>res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }

    if(root->left)addleaf(root->left,res);
    if(root->right)addleaf(root->right,res);
}





vector<int>printboundary(Treenode *root){
    vector<int>res;
    if(!root)return res;
    if(!isLeaf(root))res.push_back(root->val);
    addleftbd(root,res);
    addleaf(root,res);
    addrightbd(root,res);
    return res;
}
int main(){
    
    return 0;
}