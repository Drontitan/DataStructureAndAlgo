#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// height of left -  right <=1 so it is an balanced binary tree 


//TC-O(N )  SC-O(N) 
bool isbalanced(Treenode * root){
    return dfsheight(root)!=-1;
}

int dfsheight(Treenode * root){
    if(root==NULL)return 0;

    int left =  dfsheight(root->left);
    if(left==-1)return -1;
    int right = dfsheight(root->right);
    if(right==-1)return -1;

    if(abs(left-right)>1 )return -1;

    return max(left,right)+1;
}

int main(){
    
    return 0;
}