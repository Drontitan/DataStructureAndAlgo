#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// approach 1 : - we can make the inorder traversal and stor it in to the array till its points element
//  in it it hasnext =true  else false
//  But- TC -O(1 )   SC- O(N) for the vector

// solve the problem in O(h) space
struct Treenode
{
    int val;
    struct Treenode *left;
    struct Treenode *right;
};

class Bstiterator
{
    public:
    stack<Treenode *> st;

    // if reverse is false then next 
    // if reverse if true then before
    
    bool reverse=true;

    Bstiterator(Treenode *root,bool isreverse)
    {
        reverse =isreverse;
        pushall(root);  // pushing the all node which are in left


    }

    bool hasnext()
    {
        return !st.empty();
    }

    int next()
    {
        Treenode *node = st.top();
        st.pop();
        if(!reverse)pushall(node->right);// if not left go to right then it will go to the right
        else pushall(node->left);
        return node->val;
    }

    void pushall(Treenode * node){
       while(node){
        st.push(node);
        if(!reverse)node=node->left;
        else node=node->right;
       }
         
    }
};
class {
    public:
    bool findtarget(Treenode *root,int k){
      if(!root)return false;
      Bstiterator l(root->left,false);
      Bstiterator r(root->right,true);
    
       int i=l.next();
       int j=r.next();
       while(i<j){
        if(i+j==k)return true;
        if(k<(i+j))i=l.next();
        else j= r.next();
       }
       return false;

    }
};

int main()
{

    return 0;
}