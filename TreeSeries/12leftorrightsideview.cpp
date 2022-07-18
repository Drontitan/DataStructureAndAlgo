#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

// here we will be doing the recursive right order traversal 

// ***************** Right side****************
vector<int>rightside(Treenode *root){
    vector<int>ans;
    rightside(root,ans,0);
    return ans;
}

void rightside(Treenode *root,vector<int>ans,int level){
      
      if(root==NULL)return;

      if(level==ans.size())ans.push_back(root->val);
      if(root->right)rightside(root->right,ans,level+1);// here we have done the right first because we are 
      // taking the right side view
      if(root->left)rightside(root->left,ans,level+1);
}

//******************left side********************


vector<int>leftside(Treenode *root){
    vector<int>ans;
    rightside(root,ans,0);
    return ans;
}

void leftside(Treenode *root,vector<int>ans,int level){
      
      if(root==NULL)return;

      if(level==ans.size())ans.push_back(root->val);
         if(root->left)leftside(root->left,ans,level+1);// here we have done the left  first because we are 
      // taking the left side view
     if(root->right)rightside(root->right,ans,level+1);
}


int main(){
    
    return 0;
}