#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

//Tc-O(N )- SC-O(1)  // use the concept of the Threaded binary tree
// case 1:-  we will move the left subtree and make the thread of the right most node of left subtree to
//the root and then again move to the left for left we will find othe smaller subtree make the thread 
// to the root then if left is null and it is root itself print it and move to the right


// In-order Morris Traversal:
// 🌳 1st case: if left is null, print current node and go right
// 🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
// 🌳 3rd case: if thread is already pointed to current node, then remove the thread

// inorder 
vector<int> getinorder(Treenode *root){
    vector<int>inorder;
    Treenode *curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr= curr->right;
        }
        else {
            Treenode *prev=  curr->left;
            while(prev->right && prev->right!=NULL){
                  prev=prev->right;  
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else {
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return inorder;
}



// preorder 
vector<int> getinorder(Treenode *root){
    vector<int>preorder;
    Treenode *curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->val);
            curr= curr->right;
        }
        else {
            Treenode *prev=  curr->left;
            while(prev->right && prev->right!=NULL){
                  prev=prev->right;  
            }
            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->val);
                curr=curr->left;
            }
            else {
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}




int main(){
    
    return 0;
}