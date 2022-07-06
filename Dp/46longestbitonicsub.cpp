#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// increasin and then decreasing 
//e x: - 1 11 2 10 4 5 2 1 
//  so here it will be  1 2 10 ||  4 2 1 

int main(){
   vector<int> vec = {10, 2, 3, 6, 5, 7, 9, 1};
   // 2 3 5 7 9 
   // 1 5 6 10 // so total unique ele length will be 8 
    sort(vec.begin(), vec.end());
    int n = vec.size();
    sort(vec.begin(), vec.end());
   
    vector<int> dp1(n, 1),dp2(n,1);

    // for the increasing part 
    for (int i = 0; i < n; i++)
    {

        for (int prev = 0; prev < i; prev++)
        {
            if (vec[i]>vec[prev] && 1+dp1[prev]>dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
            }
        }
    }

    // for the decreasing part of the array 
    for (int i = n; i >=0; i--)
    {

        for (int prev = n-1; prev >=i; prev--)
        {
            if (vec[i]>vec[prev] && 1+dp2[prev]>dp2[i])
            {
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    
    int maxi=1;
    for(int i= 0 ;i<n;i++){
        maxi =max(maxi,dp1[i]+dp2[i]-1);
    }
     
     cout<<maxi<<endl;
    return 0;
}