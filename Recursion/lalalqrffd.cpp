#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void subsequencearray(vector<int>&ans,vector<int>given,int i,int sum){
  // if(sum<0)return;
   if( i==given.size()){
      // condition satisfied
      // if(sum==0){
      for(auto i :ans){
         cout<<i<<" ";
      }
      cout<<endl;
  //  }
       return ;
   }
  //  if(given[i]<=sum){
   ans.push_back(given[i]);
   subsequencearray(ans,given,i+1,sum+given[i]);
   ans.pop_back();
  //  }
   subsequencearray(ans,given,i+1,sum);

}

void subsetsum(vector<int>&ans,vector<int>given,int i,int sum){
    if(i==given.size()){
      ans.push_back(sum);
      // for(auto ele :ans){
      //   cout<<ele<<" ";
      // }
      // cout<<endl;
      return ;
    }

    subsetsum(ans,given,i+1,sum+given[i]);
    subsetsum(ans,given,i+1,sum);
}

int main(){
  string str="abc";
//  subsequence("",str);
  vector<int>vec={1,2,2};
  vector<int>ans;
  // subsetsum(ans,vec,0,0);
  sort(ans.begin(),ans.end());
  // subsequencearray(ans,vec,0,0);
  return 0;
}



