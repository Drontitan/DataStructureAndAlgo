#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// void findtheceiling(vector<ll> &arr, ll n, ll target)
// {

//     ll low = 0;
//     ll high = n - 1;
//     ll mid = low + (high - low) / 2;
//     ll mini=INT_MAX;
//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;
//         if (arr[mid] == target)
//         {
//             cout << "found";
//             return;
//         }
//         else if (arr[mid] < target)
//         {
//             low = mid + 1;
//         }
//         else if (target < arr[mid])
//         {
//             high = mid - 1;
//         }
//         if(arr[mid]>target){
//             mini=min(mini,mid);
//         }
        
//     }
//     cout<<arr[low]<<"\n";// ceiling of the traget 
//     cout<<arr[high];// floor of the traget 
//     // mid = mid + 0.5;
//     // if (target > arr[mid])
//     // {
//     //     cout << arr[mid + 1];
//     // }
//     // else
//     // {
//     //     cout << arr[mid];
//     // }
// }
void smallestcharacter(vector<char> &arr, ll n, char target)
{

    ll low = 0;
    ll high = n - 1;
    while (low <= high)
    {
       ll mid = low + (high - low) / 2;
         if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        
    }
    cout<<arr[low%arr.size()]<<"\n";// ceiling of the traget 

}
int firstandlastindex(vector<ll>arr,int target,bool findstart){
      ll ans=-1;
      ll low=0;
      ll high=arr.size()-1;
      while(low<=high){
      ll mid =low +(high-low)/2;
      if(arr[mid]>target){
         
         high=mid-1;
      }
      else if(arr[mid]<target){
          low =mid+1;
      }
      else{
          ans= mid;
          if(findstart){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      }
      return ans;
}


int main()
{
    int n;
    cin >> n;
    // vector<ll> arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // vector<char>nums1(n);
    vector<ll>nums2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    // char target;
    ll target;
    cin >> target;
    vector<ll>arr(2);
//smallestcharacter(nums1, n, target);
  ll start=firstandlastindex(nums2,target,true);
  ll end=firstandlastindex(nums2,target,false);
  arr[0]=start;
  arr[1]=end;
  cout<<arr[0]<<arr[1]<<endl;
    return 0;
}