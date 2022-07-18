#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};
// we can solve it by the previouse method by taking road to reach the both L(1st ,2nd)
// the the last node common in both the path will be the answer

// since the above method have more space complexity than require we will be refering to the new
// technique 

// we will go to the left first as usual if find the node the return that node or else null 
// then if we got node from null return it above and got to the right for the 2nd node then we will 
// got that we will be getting null and right then we will be taking the node 
// once the condition will come we will get node from boht the side int that case will take the node itself 
// that node will the lca of 1st and 2nd node 



Treenode *lowestcommonlca(Treenode *root, Treenode *p ,Treenode *q){
    if(root==NULL || p==NULL | q==NULL)return root;
    
    Treenode *left =lowestcommonlca(root->left,p,q);
    Treenode *right= lowestcommonlca(root->right,p,q);

    if(left==NULL)return right;

    else if(right==NULL)return left;
    
    else return root; // when both the left and right are not null 
}

int main(){
    
    return 0;
}