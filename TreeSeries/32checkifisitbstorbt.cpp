#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};
//TC-O(N) - SC-O(1)+stackspaceauxilary

bool isvalidbst(Treenode *root){   
      return isvalid(root,INT_MAX ,INT_MIN);
}

bool isvalid(Treenode  *root , long maxival, long minval){
    
    if(root==NULL)return true;
    if(root->val>maxival || root->val<minval)return false;

    return isvalid(root->left,root->val,minval)&&isvalid(root->right,maxival,root->val);
}

int main(){
    
    return 0;
}