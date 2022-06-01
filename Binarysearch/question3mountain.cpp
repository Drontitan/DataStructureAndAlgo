#include <bits/stdc++.h>
using namespace std;
// infinity array
typedef long long ll;

int peakofthemountain(vector<ll>&arr){
      ll low=0;
      ll high=arr.size()-1;
      while(low<high){
      ll mid =low +(high-low)/2;
      if(arr[mid]>arr[mid+1]){
         high=mid;
      }
      else {
          low =mid+1;
      }
      }
      return arr[low];
}


int main()
{

    vector<ll> arr={1,2,3,5,6,4,3,2};
     cout<<peakofthemountain(arr);
    return 0;
}