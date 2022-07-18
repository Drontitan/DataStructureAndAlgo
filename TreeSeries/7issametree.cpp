#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    int val;
   struct Treenode *left;
   struct Treenode *right;
};

// TC-O(N) SC- O(N)

bool issame(Treenode *q1, Treenode *q2){
    if(q1==NULL || q2==NULL)return q1==q2;
   
    return (q1->val==q2->val)&&issame(q1->left,q2->left)&&issame(q1->right,q2->right); 
    // we can check that the value are equal are not by traversing through each node 
    // and we have also done traversal in the same function 
    

}

int main(){
    
    return 0;
}