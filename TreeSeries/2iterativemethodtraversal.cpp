#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode
{
  int val;
  struct Treenode *left;
  struct Treenode *right;
};

// TC-O(N)  SC-O(N) -O(Height)
vector<int> preordertraversal(Treenode *root)
{ // as for pre order we go from root left right

  //  so first push root then right then left bcz we have to iterate left next and this an stack
  // so last will be call 1st
  vector<int> preorder;
  if (root == NULL)
    return preorder;

  stack<Treenode *> st;
  st.push(root);
  while (!st.empty())
  {
    root = st.top();
    st.pop();
    preorder.push_back(root->val);
    if (root->right != NULL)
      st.push(root->right);
    if (root->left != NULL)
      st.push(root->left);
  }
  return preorder;
}

// TC- O(N) SC-O(N)
vector<int> inordertraversal(Treenode *root)
{ // as here in inorder there is diff trick
  // EX -1 2 3 4 5 6 7
  //  inorder  here we will go till left and pushing the value that we are getting while moving to the left
  //  then we will insert the last left in to to our datastrcture then will check for right
  //  if right =NULL then we check in to stack and go to that element towards it right first
  //  then left like previous
  stack<Treenode *> st;
  Treenode *node = root;
  vector<int> inorder;
  if (root == NULL)
    return inorder;

  while (true)
  {
    if (node != NULL)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if (st.empty() == true)
        break;
      node = st.top();
      st.pop();
      inorder.push_back(node->val);
      node = node->right;
    }
  }
  return inorder;
}

// TC- O(N) SC-O(2*N+N)
//  *****************using the two stacks ****************//
vector<int> postordertraversal(Treenode *root)
{ // as here in inorder there is diff trick
  // EX -1 2 3 4 5 6 7
  //  here we use the two stack st1 and st2
  //  take the 1st element and put it in to the stack then remove it put it int ot st2 and in frist put its
  //  left and right 2 3 then pop 3 push it in to st2 then push left right again to st1 6 here similarly we
  //  will be puhsing them last we have 2 left in stack st1 then pop it out do the same at last
  //  print the element of stack st2 we will get the post order traversal
  vector<int> postorder;
  if (root == NULL)
    return postorder;
  stack<Treenode *> st1, st2;
  st1.push(root);

  while (!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if (root->left != NULL)
      st1.push(root->left);
    if (root->right != NULL)
      st1.push(root->right);
    while (!st2.empty())
    {
      postorder.push_back(st2.top()->val);
      st2.pop();
    }
  }
  return postorder;
}


// TC- O(N) SC-O(2*N+N)
//  *****************using the One  stacks ****************//
vector<int> postordertraversal(Treenode *root)
{ // as here in inorder there is diff trick
  // EX -1 2 3 4 5 6 7
  //  here we use the two stack st1 and st2
  //  take the 1st element and put it in to the stack then remove it put it int ot st2 and in frist put its
  //  left and right 2 3 then pop 3 push it in to st2 then push left right again to st1 6 here similarly we
  //  will be puhsing them last we have 2 left in stack st1 then pop it out do the same at last
  //  print the element of stack st2 we will get the post order traversal
  vector<int> postorder;
  if (root == NULL)
    return postorder;
  stack<Treenode *> st1, st2;
  st1.push(root);

  while (!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if (root->left != NULL)
      st1.push(root->left);
    if (root->right != NULL)
      st1.push(root->right);
    while (!st2.empty())
    {
      postorder.push_back(st2.top()->val);
      st2.pop();
    }
  }
  return postorder;
}

// ***************All in one ******************//
vector<int> preinpost(Treenode *root)
{
  // here all 3 traversal
  stack<pair<Treenode *, int>> st;
  st.push({root, 1});
  vector<int> pre, post, in; //  ds for post pre and inorder
  if (root == NULL)
    return;
  while (!st.empty())
  {
    auto it = st.top();
    st.pop();
    if (it.second == 1)
    { //  if num is 1 then preorder will store and go to left
      pre.push_back(it.first->val);
      it.second++;
      st.push(it);

      if (it.first->left != NULL)
      {
        st.push({it.first->left, 1});
      }
    }

    else if (it.second == 2)
    { // if num is 2 inorder will increase the num and will got to right
      in.push_back(it.first->val);
      it.second++;
      st.push(it);
      if (it.first->right != NULL)
      {
        st.push({it.first->right, 1});
      }
    }

    else
    { //  for the post order traversal
      post.push_back(it.first->val);
      st.pop();
    }
  }
}

int main()
{

  return 0;
}