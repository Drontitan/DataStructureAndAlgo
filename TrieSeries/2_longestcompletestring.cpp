#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    Node * link[26];
    bool flag;
    bool containskey(char ch ){
       return link[ch-'a']!=NULL;
    }
    Node * put(char ch , Node *node){
       link[ch-'a']=node;
    }

    Node* get(char ch){
        return link[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};
class Trie{
    private :
    Node *root;
    public:
    Trie(){
        root = new  Node();
    }

    void insert(string word){
        Node *node=  root;
        for(int i=0; i<word.size(); i++){
             if(!node->containskey(word[i])){
                node->put(word[i],new Node());
             }
             node= node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool CheckPrefixExist(string word){
        bool  temp  = true;
        Node *node =root;
        for(auto ele :word){
            if(node->containskey(ele)){
                node =node->get(ele);
                if(node->isEnd()==false)return false;
            }
            return false;
        }

        return true;
    }
    
};


string completeString(int  n,vector<string>vec){
    Trie trie;
    for(auto ele :vec){
        trie.insert(ele);
    }
    string longest="";

    for(auto ele : vec){
        if(trie.CheckPrefixExist(ele)){
            if(ele.length() >longest.length()){
                longest=ele;
            }
            else if(ele.length() ==longest.length() && ele<longest){
             longest=ele;
            }
        }
    }

    if(longest=="")return  "NONE";

    return longest;

}


int main(){
    
    return 0;
}