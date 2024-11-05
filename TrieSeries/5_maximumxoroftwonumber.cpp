#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//  given the two array find the maximum xor of the any element from arr1 and arr2 ;  


// insert the all the element in the form of bits in the trie 

struct Node {

    Node *links[2];

    bool ContainesKey (int bit ){
        return links[bit ]!=NULL;
    }

    Node *get(int bit){
        return links[bit];
    }

    void put(int bit , Node *node){
        links[bit]= node;
    }  
    
};

class Trie{
    private:
     Node *root;
     public:
     Trie(){
       root  = new Node();
    }


    void insert(int num){
          Node *node = root;
        for(int i=31 ;i>=0 ;i--){
            int bit  = (num>>i)&1;
            if(!node->ContainesKey(bit)){
                node->put(bit ,new Node());
            }
            node  = node->get(bit);
        }
    }

    int getmax(int num){
      Node *node = root;
      int maxnum=0;
        for(int i=31 ;i>=0 ;i--){
            int bit  = (num>>i)&1;
            if(node->ContainesKey(1-bit)){
               maxnum=maxnum |(1<<i);
                node  = node->get(1-bit);
            }
            else{
                node  = node->get(bit);
            }
        }

        return maxnum;
    }

};


int maxXor(int n, int m  ,vector<int>&vec, vector<int>&temp){
    Trie trie;
     
    for(int i=0; i<n;i++){
        trie.insert(vec[i]);
    }
    int maxi=0;
    for(int i =0; i<m; i++){
        maxi = max(maxi , trie.getmax(temp[i]));
    }

    return maxi;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int  n, m ;
        cin>>n>>m;
        vector<int>vec(n),temp(m);
        for(int i =0; i<n ;i++)cin>>vec[i];
        for(int i =0; i<m ;i++)cin>>temp[i];

        cout<<maxXor(n,m,vec,temp)<<endl;
    }
    return 0;
}