#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    int val;
    struct Treenode *left;
    struct Treenode *right;
};


// TC- O(N)--  for traversing //SC- O(N)  

//    1 2 3 4 5 6 7 
 
vector<vector<int>> Levelorder(Treenode* root){
      vector<vector<int>>vec;
      if(root==NULL)return vec;
      queue<Treenode*>q;
      q.push(root);
      while(!q.empty()){
        
        int size = q.size();
        vector<int>level;
        for(int i=0 ; i<size;i++){   // for traversiing the node like  so 1 23 4567 like wise 
            Treenode *node = q.front();
            q.pop();
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
            level.push_back(node->val);
        }
        vec.push_back(level);
      }
     return vec;
}


int main(){
    
    return 0;
}