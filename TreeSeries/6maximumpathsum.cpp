#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// find the maximum path sum  
struct Treenode{
    int val;
    struct Treenode *right;
    struct Treenode *left;
};

int maxpthsum(Treenode *root){
    int maxi=-1e9;
    solve(root,maxi);
    return maxi;
}

int solve(Treenode *root ,int &maxi){
    if(root==NULL)return ;

    int left =max(0,solve(root->left,maxi));// here for negative we have taken care that we will 
    // not comutr the negative value  if foudn we will be retuning the 0 
    int right =max(0,solve(root->right,maxi));

    maxi=max(maxi,root->val+left+right);

    return root->val+max(left,right);
}



int main(){
    
    return 0;
}