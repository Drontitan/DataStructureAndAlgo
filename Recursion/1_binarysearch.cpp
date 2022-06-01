#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int binaryserch(int arr[],int n,int low ,int high,int element){
    int mid=low+(high-low)/2;
    if(low>high){
        return -1;
    }
    if(arr[mid]==element){
        return mid;
    }
    else if(mid<element){
        return binaryserch(arr,n,mid+1,high,element);
    }
    else if(mid>element){
        return binaryserch(arr,n,low,mid-1,element);
    }
    return mid;
}
int main(){
    int n;
    int arr[]={1,2,3,4,5,6,7,8};
     n=8;
     int high=n-1;
     int low=0;
   int a= binaryserch(arr,n,low,high,5);
    cout<<a;
    return 0;
}