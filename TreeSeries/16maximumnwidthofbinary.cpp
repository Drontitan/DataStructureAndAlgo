#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};
// maximum nnumber of nodes in the level 
// here will be assining the each node some number like 1 2 3 4 but it will pverflow if we assign 
// each node new number so on each level we will be assigning the number from start 
// 0 1 2 3 4 5 like this 

int widthofbinarytree(Treenode *root){
    if(root=NULL)return  0;
    int ans=0;
    queue<pair<Treenode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first,last;
        for(int i=0 ;i <size;i++){
            int currind = q.front().second-min; // to  make the index start from 0 
            Treenode *node =q.front().first;
            q.pop();
            if(i==0)first=currind;
            if(i==size-1)last=currind;
            if(node->left)q.push({node->left,2*currind+1});
            if(node->right)q.push({node->right,2*currind+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;

}

int main(){
    
    return 0;
}