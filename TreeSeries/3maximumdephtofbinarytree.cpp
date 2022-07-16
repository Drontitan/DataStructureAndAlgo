#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//we can use hrere recursive or the level order algo 
// level order : -SC- O(n)due to queue
// recursive :-SC O(height of tree) 

//  many cases we prefer recursion 

// Recursion

// 1st we will go to the left then right 
int maxdepth(Treenode *root){
    if(root==NULL)return 0;

    int left = maxdepth(root->left);
    int right = maxdepth(root->right);

    return 1+max(left,right);
}

// level wise travesal 
int maxdepth(Treenode *root){
    queue<Treenode*>q;
    int count=0;
    q.push(root);
    while(!q.empty){
       int size =q.size();
       for(int i=0 ;i <size;i++){
        Treenode *node =q.front();
        q.pop();

        if(node->left!=NULL)q.push(node->left);
        if(node->right!=NULL)q.push(node->right);
       }
       count++;
    }

    return count;
}


int main(){
    
    return 0;
}