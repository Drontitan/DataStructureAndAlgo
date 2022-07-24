#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};
//TC-O(log2N)

Treenode *insertnode(Treenode * root,int key){
    if(root==NULL)return new Treenode(key);
    Treenode * curr= root;
    while(true){
       if(curr->val<key){
         if(curr->right)curr=curr->right;
         else{
            curr->right=new Treenode(key);
            break;
         }
       }
       else{
         if(curr->left)curr=curr->left;
         else{
            curr->left=new Treenode(key);
            break;
         }
       }
    }
    return root;
}

int main(){
    
    return 0;
}