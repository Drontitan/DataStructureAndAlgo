#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pivotelement(vector<ll>arr){

   ll start=0;
  ll end=arr.size()-1;
    while (start<=end)
    {
        ll  mid= start+(end-start)/2;
        if(mid<end &&arr[mid]>arr[mid+1]){
            return mid;
        }
         if(mid>start && arr[mid]<arr[mid-1]){
               return mid-1;
        }
        if(arr[mid]<=arr[start]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int binarysearch(vector<ll>arr,int low,int high,int target){
      while(low<=high){
      ll mid =low +(high-low)/2;
      if(arr[mid]>target){
         
         high=mid-1;
      }
      else if(arr[mid]<target){
          low =mid+1;
      }
      else{
         return mid;
      }
      }
      return -1;
}

int main()
{
    vector<ll>arr={4,5,6,7,0,1,2};
    ll pivot =pivotelement(arr);
    int target=0;
    ll firsthalf=binarysearch(arr,0,pivot,target);
    ll lasthalf=binarysearch(arr,pivot+1,arr.size()-1,target);
     if (firsthalf != -1)
    {
        cout << firsthalf << endl;
    }
    else
    {
        cout << lasthalf << endl;
    }
    return 0;
}