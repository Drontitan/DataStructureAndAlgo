#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// falten the binary tree to the linkedlist  the linkedlist will look like the preorder traversal 

// but here you dont watn to create the new node here you want to simply convert the binary tree 
// like the preorder traversal all the nodes towards its right

// approach 1: recursive 
/*


TC-O(N) SC-O(N)
prev=NULL
flatten(node){  //  here we will first move towards the right then left 
 
  if(node)return NULL;
  flatten(node->right);
  flatten(node->left);
   
  node->right=prev;
  node->left=NULL;

  prev=node;
}

//approach :- 2 stack with iterative

// here we will taking root push in to the stack then  mark curr to root then pop the root 
// now push left and right then mark curr to stack top and and left to null similarly follow 
stack<int>st;
while(!stack.empty()){
    curr=st.top();
    st.pop();

    if(curr->right)st.push(curr->right);
    if(curr->left)st.push(curr->left);

    if(!st.empty()){
        curr->right=st.top();
        curr->left=NULL;

    }
}

apporoach :-3  

curr =root;
while(curr!=NULL){
    if(curr->left!=NULL){
        prev=prev->left;
        while(prev->right)prev=prev->right;
        prev->right=curr->right;
        curr->right=curr->left;
    }
    curr=curr->right;
}







*/

int main(){
    
    return 0;
}