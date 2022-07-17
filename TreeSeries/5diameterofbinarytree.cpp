#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// diameter : -  longest path between any two nodes 
// path does not need to pass via root 

struct Treenode {
    int val;
    struct Treenode *right;
    struct Treenode *left;
};



int diameterofbinarytree(Treenode * root){
    int diam=0;
    height(root,diam);
    return diam;
}

int  height(Treenode * root , int  &diam){
    if(root==NULL)return 0;

    int left = height(root->left,diam);
    int right = height(root->right,diam);

     diam=max(diam,left+right);// here we are finding the maximum height at each node 

     return 1+max(left,right); // max of left and right tree
}

int main(){
    
    return 0;
}