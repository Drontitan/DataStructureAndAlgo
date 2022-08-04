#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// we have to find the maximum array that have beeen partitionarrayed
// none of the partitionarray have more  than length k

// EX: -  [1 15 7 9 2 5 10] : k=3;
// no [partitionarray have elemngt more than k ]
// if partitionarray  if we partitionarray

//  1 15 | 7 9  2 |5  10

// 15 15  | 9 9 9 | 10 10  // we have took the maximum element from them

// then we will take the sum 15*2+9*3+10* 77 note this is not the maximum ans but concept


// recursion
int partitionarray(int i, int k,int n, vector<int>&vec)
{

    if (i == n)
        return 0;
    int len = 0, maxi = INT_MIN, maxans = INT_MIN;
    for (int j = i; j < min( i + k,n); j++)
    {
        len++;
        maxi = max(maxi, vec[j]);
        int sum = (maxi * len) + partitionarray(j + 1, k,n, vec);
        maxans = max(maxans, sum);
    }
    return maxans;
}


// memoization
//TC- O(N)*O(K)  SC- O(N)+O(N )
int partitionarraymemo(int i, int k, vector<int>&vec,vector<int>&dp)
{
   int n=vec.size();
    if (i == n)
        return 0;
    int len = 0, maxi = INT_MIN, maxans = INT_MIN;
    if(dp[i]!=-1)return dp[i];
    for (int j = i; j < min( i + k,n); j++)
    {
        len++;
        maxi = max(maxi, vec[j]);
        int sum = (maxi * len) + partitionarraymemo(j + 1, k, vec,dp);
        maxans = max(maxans, sum);
    }
    return dp[i]=maxans;
}

// tabulation
int partitionarrayiterative(int n, int k, vector<int>&vec,vector<int>&dp)
{

    
    for(int i =n-1;i>=0;i--){
    int len = 0, maxi = INT_MIN, maxans = INT_MIN;
    for (int j = i; j < min( i+ k,n); j++)
    {
        len++;
        maxi = max(maxi, vec[j]);
        int sum = (maxi * len) + dp[j+1];
        maxans = max(maxans, sum);
    }
        dp[i]=maxans;
    }
   return dp[0];

}


int main()
{
    vector<int> vec = {1,20,13,4,4,1};
    int n = vec.size();
    int k = 3;
    vector<int>dp(n,-1);
    vector<int>dpit(n+1,0);
    cout << partitionarray(0, k,n, vec)<<endl;
    cout << partitionarraymemo(0, k, vec,dp)<<endl;
    cout << partitionarrayiterative(n, k, vec,dpit)<<endl;
    return 0;
}