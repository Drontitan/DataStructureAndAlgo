#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// we can  take the element any number of times 
void solvecomninationsum1(vector<int>&vec,vector<int>ans,int target ,int i){

    if(i>=vec.size()){
        if(target==0){
            for(auto ele:ans)cout<<ele<<" ";
            cout<<endl;
        }
        return ;
    }
   if(vec[i]<=target){
    ans.push_back(vec[i]);
    solvecomninationsum1(vec,ans,target-vec[i],i);
    ans.pop_back();
    }
    solvecomninationsum1(vec,ans,target,i+1);
}

// we have to take the element only once but it must not contain the duplicate combinations *******

// brute force if 2^n *K *logn logn for insert in to another set 


// now instead of taking and  notaking simply we wil take and not take whole subsequence 
void solvecomninationsum2(vector<int>&vec,vector<int>&ans,int target ,int ind){

        if(target==0){
            for(auto ele:ans)cout<<ele<<" ";
            cout<<endl;
        return ;
        }
    
   for(int i=ind; i<vec.size();i++){
    if(i>ind && vec[i]==vec[i-1])continue; // for not having the duplicate elements and i>ind for taking the 
    // current element and after the element not taking duplicate 
    if(vec[i]>target)break; 
    ans.push_back(vec[i]);
    solvecomninationsum2(vec,ans,target-vec[i],i+1);
    ans.pop_back();
   }
  
}



int main(){
    vector<int>vec={10,1,2,7,6,1,5};
    vector<int>ans;
    int target=8;
    //  solvecomninationsum1(vec,ans,target,0);
     sort(vec.begin(),vec.end());// so it will contain the element int the increasing order 
     solvecomninationsum2(vec,ans,target,0);
    return 0;
}