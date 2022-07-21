#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//we will be given the root we have convert root it into the string then for NULL node # 
// in deserialise the string is again converted to the root 

struct Treenode {
    struct Treenode *left;
    struct Treenode *right;
    int val;
};

//TC-O(N) SC-O(N) 

string serialise(Treenode *root){
   if(!root)return "";
   queue<Treenode*>q;
   string ans;
   q.push(root);
   while(!q.empty()){

        Treenode *node =q.front();
        q.pop();
        if(node==NULL)ans.append("#,"); // here we are appending the null node as # 
        else ans.append(to_string(node->val)+',');
        if(node){
            q.push(node->left);
            q.push(node->left);
        }
    }

   cout<<ans<<endl;
   return ans;

}

Treenode *deserialise(string data){
    if(data.size()==0)return NULL;
    stringstream s(data);
    string str;
    getline(s,str,','); // it will iterate on , separated character 
    Treenode *root= new Treenode(stoi(str));
    queue<Treenode *>q;
    q.push(root);
    while(!q.empty()){
       Treenode *node = q.front();
       q.pop();

       getline(s,str,',');  // for the left node 
       if(str=="#")node->left=NULL;
       else{
          Treenode *leftnode =new Treenode(stoi(str));
          node->left=leftnode;
          q.push(leftnode);
       }
       getline(s,str,',');  // for the right node
       if(str=="#")node->right=NULL;
       else{
          Treenode *rightnode =new Treenode(stoi(str));
          node->right=rightnode;
          q.push(rightnode);
       }


    }
    return root;
}
   

int main(){
    
    return 0;
}