#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};
//TC-O(Height of tree )  SC-O(1)+auxilaryspace
Treenode *lowestcommon(Treenode *root ,Treenode *p ,Treenode *q){
    if(root==NULL)return NULL;
    Treenode *node =root;
    if(p->val>node->val && q->val>node->val)return lowestcommon(root->right,p,q);

      if(p->val<node->val && q->val<node->val)return lowestcommon(root->left,p,q);

      return root;
}



int main(){
    
    return 0;
}