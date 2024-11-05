#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};


// inorder will always be sorted so we can perform inorder -approach -1 

//TC-O(N)  S(N)
//  kht largest will be n-kth smallest

int kthsmallest(Treenode *root,int k){
     
     if(root==NULL)return NULL;
     stack<Treenode *>st;
     Treenode *node = root;
     int count=0;
     while(true){
        if(node){
            st.push(node);
            node=node->left;
     }
     else{
        if(st.empty())break;
        node = st.top();
        st.pop();
        count++;
        if(count==3)return node->val;
     }
    }
}


int main(){
    
    return 0;
}