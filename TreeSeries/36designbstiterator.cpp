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
    stack<Treenode *> st;
    Bstiterator(Treenode *root)
    {
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
        pushall(node->right);// if not left go to right then it will go to the right
        return node->val;
    }

    void pushall(Treenode * node){
       while(node){
        st.push(node);
        node=node->left;
       }
         
    }
};

int main()
{

    return 0;
}