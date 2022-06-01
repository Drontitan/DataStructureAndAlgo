#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxelement(int arr[],int n){
    if (n == 1)
        return arr[0];
    return min(arr[n - 1], maxelement(arr, n - 1));
}
int main(){
    int arr[]={1, 4, 3, -5, -4, 8, 6};
     cout<<maxelement(arr, 7);
     return 0;
}