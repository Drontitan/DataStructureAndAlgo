#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

//TC-O(N) SC-O(N) 

bool issymmetric(Treenode *root){
   return root==NULL || symmetrichelp(root->left,root->right);
}

bool symmetrichelp(Treenode *left ,Treenode *right){// 

    if(left==NULL || right==NULL)return right==left;
    if(left->val!=right->val)return false;

    return symmetrichelp(left->left,right->right)&&symmetrichelp(left->right,right->left);

}

int main(){
    
    return 0;
}