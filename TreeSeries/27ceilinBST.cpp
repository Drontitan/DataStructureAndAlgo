#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// we have give the lowest number which is  greater than equal to key 

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};

int findceil(Treenode *root,int key){
    int ceil=-1;
    while(root){
        if(root->val==key){
            ceil=root->val;
            return ceil;
        }
        if(root->val<key){
            root=root->right;
        }
        else{
            ceil=root->val;
            root=root->left;
        }
    }
    return ceil;
}


int main(){
    
    return 0;
}