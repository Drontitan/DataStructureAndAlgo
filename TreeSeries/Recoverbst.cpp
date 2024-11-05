#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode
{
    int val;
    struct Treenode *left;
    struct Treenode *right;
    struct Treenode *prev;
    struct Treenode *middle;
    struct Treenode *curr;

};

void inorder(Treenode *root){
    if(!root)return ;
    inorder(root->left);

    if(prev!=NULL && (root->val<prev->val)){
         
         if(first==NULL){
            first=prev;
            middle=root;
         }

         else{
            last=root;
         }
         prev=root;
    }
}

int main(){
    
    return 0;
}