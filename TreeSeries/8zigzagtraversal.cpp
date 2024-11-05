#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// it kind of 1 level in 1 order then other will we traversing opposite direction  
// 1 2 3 4 5 6 7 
// then traversal will be           1 2 3 7 6 5 4                                


struct Treenode {
    int val;
    struct Treenode *left;
    struct Treenode *right;
};

 //TC-O(N )  SC-O(N)
vector<vector<int>> zigzagorder(Treenode* root){
      vector<vector<int>>vec;
      if(root==NULL)return vec;
      queue<Treenode*>q;
      q.push(root);
      bool ltor = true;
      while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        for(int i=0 ; i<size;i++){   // for traversiing the node like  so 1 23 4567 like wise 
            Treenode *node = q.front();
            q.pop();

            int index = (ltor)?i:size-1-i;
            level[index]=node->val;
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
        }
        ltor=!ltor;
        vec.push_back(level);
      }
     return vec;
}




int main(){
    
    return 0;
}