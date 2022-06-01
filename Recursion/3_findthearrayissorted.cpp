#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int checkarray(int arr[],int index){
     if (index == arr.size() - 1)
     {
         return true;
     }
     return arr[index]<arr[index+1] && checkarray(arr,index+1);
}

int main(){
    int arr[]={1,2,4,3,5,7,8,9};
    int a= checkarray(arr,0);
   cout<<a;
    return 0;
}