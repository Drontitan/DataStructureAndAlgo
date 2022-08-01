#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// largest divisible subset ex:-  1 16 7  8 4   { 1 16 8  4 }are divisible 
// her each element id divisible array should have distinct numbers 


// here we will be just using previous code just sorting in the 1 st and making change in the condition
//TC- O(N*N) - SC- O(N) 
int main(){
       vector<int> vec = {10, 2, 3, 6, 5, 7, 9, 1};
    int n = vec.size();
    sort(vec.begin(),vec.end());
     int maxi=1;
    vector<int>dp(n,1),hash(n);
    int lastindex=0;
    for(int i=0;i<n;i++){
         hash[i]=i;
        for(int prev =0 ;prev<i;prev++){
            if(vec[i]%vec[prev]==0 && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
        }
    }
   vector<int>temp;
  temp.push_back(vec[lastindex]);
   while(hash[lastindex]!=lastindex){
    lastindex=hash[lastindex];
    temp.push_back(vec[lastindex]);
   }
   reverse(temp.begin(),temp.end());
   for(auto ele  :temp)cout<<ele<<" ";
   cout<<endl;
   cout<<maxi;

    return 0;
}