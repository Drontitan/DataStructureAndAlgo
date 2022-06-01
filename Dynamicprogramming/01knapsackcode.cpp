#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

int knapsack(int wt[],int val[],int w,int n ){
    if(w==0 || n==0){
        return 0;
    }

    if(wt[n-1]<=w){
       return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int wt[4]={1,3,4,4};
   int val[4]={1,4,5,7};
   int w=10;
   int n=4;
  
  cout<<knapsack( wt, val, w,n);
    return 0;
}
















