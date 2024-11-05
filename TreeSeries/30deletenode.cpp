#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};
//TC- O(height of tree )
Treenode *deletenode(Treenode *root,int key ){
    if(root==NULL)return NULL;
    if(root->val==key)return helper(root);
    Treenode *dummy=root;

    while(root!=NULL){
        if(root->val>key){
            if(root->left!=NULL && root->left->val==key){
                root->left =helper(root->left);
                break;
            }
            else root=root->left;
        }
        else{
            if(root->right!=NULL && root->right->val==key){
                root->right =helper(root->right);
                break;
            }
            else root=root->right;
        }
    }

    return dummy;
}

Treenode *helper(Treenode *root){
    if(root->left==NULL)return root->right;

    if(root->right=NULL)return root->left;

    Treenode * rootrightchild =root->right;
    Treenode *lastright = findlastright(root->left);
    lastright->right= rootrightchild;

    return root->left;
    
}

Treenode *findlastright(Treenode *root){
    if(root->right==NULL)return root;

    return findlastright(root->right);
}


int main(){
    
    return 0;
}