#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sumoftraingleofarray(int arr[],int n){
    
    if(n<1){
        return;
    }
    int temp[n - 1];
    for (int i = 0; i < n; i++)
    {
       int x = arr[i] + arr[i + 1];
        temp[i] = x;
    }
    sumoftraingleofarray(temp,n-1);
    for (int i = 0; i < n; i++)
    {
            cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    sumoftraingleofarray(arr, n);
     return 0;
}