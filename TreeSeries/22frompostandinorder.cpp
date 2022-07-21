#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};
//TC- O(N)*log(N)|O(N)*N*log(N)  SC - O(N)


// construct binary tree from the inorder and postorder traversal 
Treenode * builttree(vector<int>&inorder,vector<int>&postorder){
    map<int,int>mp;

    for(int i= 0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    Treenode *node = buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    return node;
}

Treenode *buildtree(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int 
instart,int inend,map<int,int>mp){
    if(poststart>postend || instart>inend)return NULL;

   Treenode * root =new Treenode(postorder[poststart]);
   int inroot = mp[root->val];
   int numsleft =inroot-instart;

   root->left =buildtree(postorder ,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mp);

   root->right=buildtree(postorder ,poststart+numsleft,postend-1,inorder,inroot+1,inend,mp);
   return root;
}


int main(){
    
    return 0;
}