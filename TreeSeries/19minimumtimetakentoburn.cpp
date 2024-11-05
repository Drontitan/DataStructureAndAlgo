#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// here what will we do first marke the parent with their child using the level wise traversal and storing 
// them accordingly   then we will traverse again after levelwise so we will check wo is burnt and who #include <string>
// not like will take 1sec to burn to side nodes then 2 sec which are 2 distance away from them
// and 3 4 5 ....  

//Tc-O(N)+O(N)~O(N); SC-O(N)

int findmaxdist(map<BinaryTreenode<int>*,BinaryTreenode<int>*>&mp,BinaryTreenode<int>*target){
    queue<BinaryTreenode<int>*>q;
    map<BinaryTreenode<int>*,int>vis;
    q.push(target);
    vis[target]=1;
    int maxi=0;
    while(!q.empty()){
        int size=q.size();
        int flag=0;
        for(int i=0 ;i <size;i++){
            auto node =q.front();
            q.pop();
            if(node->left && !vis[node->left]){ // we have to simulatneoulsy right and left both as same time 
            // as well as parent node so all are if 
                flag=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                flag=1;  // if burning anynone then mnarking the flag as one 
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mp[node] && !vis[mp[node]]){  //  check if parent pointer exist if exist then check visited 
            // if not move towards it 
                flag=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(flag)maxi++;
    }
    return maxi;
}

BinaryTreenode<int>*bfstoparentmaps(BinaryTreenode<int>*root,map<BinaryTreenode<int>*,BinaryTreenode<int>*>&mp,
  int start){
   queue<BinaryTreenode<int>*>q;
   BinaryTreenode<int>*res;
   q.push(root);
   while(!q.empty()){
    BinaryTreenode<int>*node =q.front();
    if(node->val==start)res=node;
    q.pop();
    if(node->left){
        mp[node->left]=node;
        q.push(node->left);
    }
    if(node->right){
        mp[node->right]=node;
        q.push(node->right);
    }

   }
   return res;
}

int timetoburntree(BinaryTreenode<int>*root,int start){
    map<BinaryTreenode<int>*,BinaryTreenode<int>*>mp;// map
    BinaryTreenode<int>*target =bfstoparentmap(root,mp,start);
    int maxi=findmaxdist(mp,target);
    return maxi;
}

int main(){
    
    return 0;
}