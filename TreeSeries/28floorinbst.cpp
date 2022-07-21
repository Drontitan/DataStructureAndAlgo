#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// greatest value that is  smaller than or equal to the  key

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};

int findfloor(Treenode *root,int key){
    int floor=-1;
    while(root){
        if(root->val==key){
            floor=root->val;
            return floor;
        }
        if(root->val<key){
            floor=root->val;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
}


int main(){
    
    return 0;
}