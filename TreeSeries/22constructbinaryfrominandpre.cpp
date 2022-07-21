#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};
//TC- O(N)  SC - O(N)


// construct binary tree from the inorder and preorder traversal 
Treenode * builttree(vector<int>&inorder,vector<int>&preorder){
    map<int,int>mp;

    for(int i= 0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    Treenode *node = buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    return node;
}

Treenode *buildtree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int 
instart,int inend,map<int,int>mp){
    if(prestart>preend || instart>inend)return NULL;

   Treenode * root =new Treenode(preorder[prestart]);
   int inroot = mp[root->val];
   int numsleft =inroot-instart;

   root->left =buildtree(preorder ,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mp);

   root->right=buildtree(preorder ,prestart+numsleft+1,preend,inorder,inroot+1,inend,mp);
   return root;
}


int main(){
    
    return 0;
}