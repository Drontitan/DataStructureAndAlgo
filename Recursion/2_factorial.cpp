#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


vector<vector<int>> numberofsearchelele( vector<int>&vec,int i,int key){
     vector<vector<int>>ans;
     if(i==vec.size())return;
     if(vec[i]==key)ans.push_back(vec);
     numberofsearchelele(vec,i+1,key);
}

int main(){
   vector<int>vec={1,3,4,4,6,7,8};
   numberofsearchelele(vec,0,4);
   // cout<<ans.size()<<endl;
   for(auto i : ans)cout<<i<<endl;
   return 0;
}
