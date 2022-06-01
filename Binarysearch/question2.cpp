#include <bits/stdc++.h>
using namespace std;
// infinity array
typedef long long ll;

int binarysearch(vector<ll>arr,int target,int low,int high){
      ll ans=-1;
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
      return ans;
}
int mentionthesize(vector<ll>arr,int target){
    int start=0;
    int end=1;
    while(target>arr[end]){
    int temp=start+1;
    end=end+(end-start+1)*2;
    start=temp;
    }
    return binarysearch(arr,target,start,end);
}


int main()
{

    vector<ll> arr={2,3,5,6,7,8,10,11,12,15,20,23,30};
    int target=30;
     cout<<mentionthesize(arr,target);
    return 0;
}