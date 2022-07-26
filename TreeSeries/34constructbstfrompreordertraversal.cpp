#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};
// construvt binary search from preorder traversl 

//approach -1 do it like manually checking 

// approach -2 by sorting the preorder traversal we wil get the inorder traversal so we can use bt 
// previous method  to do so 

// approach -3 we will use range like we did in is bst but this time we will be using the  only
// the upper bound   

Treenode *bst(vector<int>&vec){
  int i=0 ;
  return build(vec,i,INT_MAX);
}

Treenode *build(vector<int>&vec ,int i, int upperb){
     if(i==vec.size() || vec[i]>upperb)return NULL;

      Treenode *root = new Treenode(vec[i++]);
     root->left = build(vec,i,root->val);
     root->right = build(vec,i,upperb);

     return root;
}


int main(){
    
    return 0;
}