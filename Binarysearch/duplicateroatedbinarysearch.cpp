#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pivotelement(vector<ll>arr){

   ll start=0;
  ll end=arr.size()-1;
    while (start<=end)
    {
        ll mid= start+(end-start)/2;
        if(mid<end &&arr[mid]>arr[mid+1]){
            return mid;
        }
         if(mid>start && arr[mid]<arr[mid-1]){
               return mid-1;
        }
        // if the elements at start end and middle are equal the skip them 
        if(arr[mid]==arr[start]&&arr[mid]==arr[end]){
             if(arr[start]>arr[start+1]){
                 return start;
             }
             start++;
             if(arr[end]<arr[end-1]){
                 return end-1;
             }
             end--;
        }
        // left side is sorted the n pivot should be in the right 
        else if(arr[start]<arr[mid]||(arr[start]==arr[mid]&& arr[mid]>arr[end])){
            start=mid+1;
        }
        else{
            end=mid-1;
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
    vector<ll>arr={2,2,6,7,0,1,2};
    ll pivot =pivotelement(arr);
    int target=0;
    ll firsthalf=binarysearch(arr,0,pivot,target);
    ll lasthalf=binarysearch(arr,pivot+1,arr.size()-1,target);
    cout<<pivot<<endl;
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