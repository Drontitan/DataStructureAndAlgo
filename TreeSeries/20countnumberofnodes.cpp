#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


//Tc-O(logn)^2; SC-O(N )

// if we use the level order or recursion it will require the atleast of O(N) time complexity 
// but we have to compute it in less than O(N) as per the question in complete tree

// we will move to each node then will check that the tree is binary tree if its left height equal tothe 
// right height then it is thenwe can directly apply the formula 2^n-1 
// other wise we will go depper by taking the (1+left subtree+ right subtree )

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

int countnode(Treenode *root){

    int lh = findleftheight(root->left);
    int rh= findrightheight(root->right);

    if(lh==rh)return (1<<lh)-1;

    return 1+countnode(root->left)+countnode(root->right);
}


int findleftheight(Treenode *root){
    int height;
    while(root){
        height++;
        root=root->left;
    }
    return height;
}

int findrightheight(Treenode *root){
    int height;
    while(root){
        height++;
        root=root->right;
    }
    return height;
}


int main(){
    
    return 0;
}