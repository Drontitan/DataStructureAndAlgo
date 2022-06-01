#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

vector<vector<int>> combinationSum(vector<int>&candidates, int target){
   ll sum=0;
   vector<ll>vec;
    vector<ll>arr;
    if(sum>target){
        return arr;
    }
    for (int i = 0; i <candidates.size(); i++)
    {
        sum+=candidates[i];
        if(sum==target){
            
        }
    }
    arr.insert(arr.begin(),vec.begin(),vec.end());
    
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll n;
   cin>>n;
     vector<ll>vec(n);
     for (int i = 0; i <n; i++)
     {
         cin>>vec[i];
     }
     for (int i = 0; i <vec.size(); i++)
     {
         
     }
     
    

    return 0;
}