#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};

Treenode *Bst(Treenode * root,int val){
    while(root!=NULL && root->val!=val){
        root = val<root->val?root->left:root->right;
    }
    return root;
}

int main(){
    
    return 0;
}