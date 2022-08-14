#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve1(vector<int>&arr,int i,vector<int>vec,int target,int sum){

   if(i>=vec.size()){
    if(sum==target){
    for(auto ele:arr)cout<<ele<<" ";
    cout<<endl;
   }
    return;
   }

   
   sum+=vec[i];
   arr.push_back(vec[i]);
   solve1(arr,i+1,vec,target,sum);
   sum-=vec[i];
   arr.pop_back();
   
   solve1(arr,i+1,vec,target,sum);
    
}
void solve2(vector<int>&arr,int i,vector<int>vec,int target){

   if(i>=vec.size()){
    if(target==0){
    for(auto ele:arr)cout<<ele<<" ";
    cout<<endl;
   }
    return;
   }

   if(vec[i]<=target){
   arr.push_back(vec[i]);
   solve2(arr,i+1,vec,target-vec[i]);
   arr.pop_back();
   }
   solve2(arr,i+1,vec,target);
    
}

bool solve3(vector<int>&arr,int i,vector<int>vec,int target,int sum){

   if(i>=vec.size()){
    if(sum==target){
    for(auto ele:arr)cout<<ele<<" ";
    cout<<endl;
    return true;
   }
    return false;
   }

   
   sum+=vec[i];
   arr.push_back(vec[i]);
   if(solve3(arr,i+1,vec,target,sum)==true)return true;
   sum-=vec[i];
   arr.pop_back();
   
   if(solve3(arr,i+1,vec,target,sum)==true)return true;
   
   return false;
}

int solve4(vector<int>&arr,int i,vector<int>vec,int target){

   if(i>=vec.size()){
    if(target==0){
     return 1;
   }
    return 0;
   }
   
   int take=0;
   if(vec[i]<=target){
   arr.push_back(vec[i]);
   take= solve4(arr,i+1,vec,target-vec[i]);
   arr.pop_back();
   }
   int nottake = solve4(arr,i+1,vec,target);
    
   return take+nottake;
}
int main(){
    vector<int>arr={1,2,3,4};
    vector<int>ans;
    int target=5;
    int sum=0;
   //  solve1(ans,0,arr,target,sum);.///
    // solve2(ans,0,arr,target);
   //  solve3(ans,0,arr,target,sum);
    cout<<solve4(ans,0,arr,target);
    return 0;
}