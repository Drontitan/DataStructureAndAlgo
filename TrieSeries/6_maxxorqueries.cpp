#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// we have to calculate the maximum xor according to the queries like we have given the array containing
// the element and the queries x1 ai where we have take the xor of xi with the element in array less than 
// ai 

// so here calculate the max xor in all the queries 

// just do one thing that sort the queries according ot the ai then push in to the trie and calculate 
// further as the ai will increase it will always have the element less than the it in trie so it wil be easy


struct Node {
    Node *links[2];
    
    Node *get(int bit){
     return links[bit];
    }

    void put(int bit , Node *node){
     links[bit]=node;
    }
    bool containsKey(int bit){
        return   links[bit]!=NULL;
    }

};

class Trie{
    private :
    Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(int num ){
       Node *node  =root;
       for(int i=31; i>=0 ;i--){
        int bit = (num>>i)&1;
        if(!node->containsKey(bit)){
            node->put(bit , new Node());
        }
        node = node->get(bit);
       }
    }
     
     int getmax(int num){
      Node *node = root;
      int maxnum=0;
        for(int i=31 ;i>=0 ;i--){
            int bit  = (num>>i)&1;
            if(node->containsKey(1-bit)){
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


vector<int>maxxorqueries(vector<int>&arr ,vector<vector<int>>&queries){
     sort(arr.begin(),arr.end());
     vector<pair<int,pair<int,int>>>off;
      int m = queries.size();
      for(int i=0; i< m ;i++){
        off.push_back({queries[i][1],{queries[i][0],i}});
      }

      sort(off.begin(),off.end()); 
      vector<int>ans(m,0);
      Trie trie;
      int  ind =0;
      int n = arr.size();
      for(auto ele: off){
        int ai = ele.first;
        int xi = ele.second.first;
        int i  = ele.second.second;
        while(ind<n && arr[ind]<=ai){
          trie.insert(arr[ind]);
          ind++;
        }

        if(ind==0)ans[i]=-1;
        else ans[i]=trie.getmax(xi);
      }

      return ans;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>vec(n);
        vector<vector<int>>queries;
        vector<int>ans;
        for(int i=0; i<n ;i++)cin>>vec[i];
        while(m--){
            int a,b;
            cin>>a>>b;
            queries.push_back({a,b});
        }

        ans = maxxorqueries(vec,queries);
        for(auto ele:ans)cout<<ele<<" ";
        cout<<endl;

    }
    return 0;
}