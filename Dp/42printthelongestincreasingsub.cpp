#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here is the diff method of calculating the longest increasing subsequence 

//  here we will take the dp array of size n and all element intially will be 1
// ex :     5 4 11 1 16 8 
// here     1 1  1 1  1 1
//  for 5   1 1  1 1  1 1
// for 4    1 1  1 1 1 1 
// for 11   1 1  1+1=2
// for 1    1 1 2 1 1 1
// for 16   1 1 2 1 2+1=3 1 
// like we willl be updating the element by checking all the previous once
int main(){
    vector<int> vec = {10, 2, 3, 6, 5, 7, 9, 1};
    int n = vec.size();
    // vector<int>dp(n,1);
     int maxi=1;
     // **********this was the code to find the lis by new technique
    // for(int i=0;i<n;i++){
    //     for(int prev =0 ;prev<i;prev++){
    //         if(vec[i]>vec[prev]){
    //             dp[i]=max(1+dp[prev],dp[i]);
    //         }
    //     }
    //     maxi=max(maxi,dp[i]);
    // }

    // cout<<maxi<<endl;    

    //  how to print the lis 
    vector<int>dp(n,1),hash(n);
    int lastindex=0;
    for(int i=0;i<n;i++){
         hash[i]=i;
        for(int prev =0 ;prev<i;prev++){
            if(vec[i]>vec[prev] && 1+dp[prev]){
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