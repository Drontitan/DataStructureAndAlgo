#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};
// at any node the the node will have tha value equal to the right and left children 
// node->val = node-left->val+node->right->val;
// it it not follows then you can increment the node by +1 any  number of times 

// here what we have done is we will check that node->left+ node->right is greater or node is greater 
// if child sum is greater then will update the root if root is greater then will update the childs
// 


//Tc-O(N) SC-O(N)
void change(Treenode  *root){
    if(root==NULL)return ;
    int child;
    if(root->left)child+=root->left->val;

    if(root->right)child+=root->right->val;

    if(child>=root->val)root->val=child;
    else{
        if(root->left)root->left->val=root->val;
        if(root->right)root->right->val=root->val;
    }

    change(root->left);
    change(root->right);
   // when the call is returning back 
   // it should take the value of left and right child so we that we have done here 
    int tot=0;
    if(root->left)tot+=root->left->val;
    if(root->right)tot+=root->right->val;
    if(root->left or root->right)root->val=tot; // for checking the leaf node then we will update or else no
}

int main(){
    
    return 0;
}