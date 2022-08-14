#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//TC- O(N)
void solve(vector<int>&arr,int i,vector<int>vec){

   if(i>=vec.size()){
    for(auto ele:arr)cout<<ele<<" ";
    cout<<endl;
    return;
   }

   arr.push_back(vec[i]);
   solve(arr,i+1,vec);// take 
   arr.pop_back();
   solve(arr,i+1,vec); // nottake
    
}

int main(){
    vector<int>arr={1,2,3,4};
    vector<int>ans;
    solve(ans,0,arr);
    return 0;
}