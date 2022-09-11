#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here we were given the alien dictionary there were some string arranged in that
// ""




// then wehave to find the who comes before whom in that 

int main(){
    int n, k;
    cin>>n>>k;
    vector<string>dict={"baa","abcd","abca","cab","cad"};
    for(int i=0 ;i <n ;i ++){
        string str;
        cin>>str;
        dict.push_back(str);
    }
    // for(auto ele:dict ){
    //     cout<<ele<<" "<<endl;
    //  }
    vector<int>adj[k];
    for(int i=0 ; i<n-1;i++){
        string s1= dict[i];
        string s2= dict[i+1]; 
        int minlen = min(s1.size(),s2.size());
        // cout<<minlen<<endl;
        for(int j =0; j<minlen ;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]- 'a'].push_back(s2[j]- 'a');
                 break;
                }
        }
    }
    

    // then applying the topo sort for 
   int indegree[k]={0};

//    for(int i=0 ;i < k ;i++){
//     cout<<i<<" ";
//     for(auto ele: adj[i])cout<<ele<<" ";
//     cout<<endl;
//    }

   vector<int>topo;
   queue<int>q;
   for(int i =0; i<k; i++){
    for(auto ele: adj[i]){
        // cout<<ele<<" ";
        indegree[ele]++;
    }
   }
    for(int i= 0; i<n; i++){
      if(indegree[i]==0)q.push(i);
   }

   while(!q.empty()){
       int node =q.front();
       q.pop();
       topo.push_back(node);
       for(auto ele :adj[node]){
        indegree[ele]--;
        if(indegree[ele]==0)q.push(ele);
       }
   }

   string ans="";
   for(auto ele: topo)ans =ans+char(ele+'a');
   cout<<ans<<endl;

    return 0;
}