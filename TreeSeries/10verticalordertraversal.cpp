#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

// we have to traverse vertically 
// EX:-                1
//                   /    \
//                 2       3
//                /  \     / \
//              4     10  /  10
//               \      9  
//                5 
//                   \                               
//                    6

// so the traversal will,be   4 -  2 5 -  1 9 10 6 -  3 -  10 

// we will be taking level and vertically and horizontally
// vertical levell start fromm mid as root as 0 then towrds left -1 each time we traverse left and +1 
// each time we traverse right

// we use map as map<vertical<horizontal<nodes>>>  and qeue as <node<vertical,horizontal>>     



vector<vector<int>>verticalorder(Treenode *root){
     
    map<int,map<int,multiset<int>>>mp;
    queue<pair<Treenode *,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Treenode *node = p.first;
        int x= p.second.first,y=p.second.second;
        mp[x][y].insert(node->val);
        
        if(node->left)q.push({node->left,{x-1,y+1}});

        if(node->right)q.push({node->right,{x+1,y+1}});

    }

    vector<vector<int>>ans;

    for(auto it:mp){
        vector<int>col;
        for(auto ele : it.second){
          col.insert(col.end(),ele.second.begin(),ele.second.end());
        }
        ans.push_back(col);
    }
     
     return ans;

}


int main(){
    
    return 0;
}