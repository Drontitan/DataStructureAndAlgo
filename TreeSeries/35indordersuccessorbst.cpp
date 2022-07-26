#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


//TC-O(H)
// Sc-O(1)
struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};

Treenode *inordersuccessor(Treenode *root,int key){
       Treenode *successor=NULL;

       while(root){
        if(key>=root->val){
             root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
       }
       return successor;
}

int main(){
    
    return 0;
}