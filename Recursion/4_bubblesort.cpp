#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void bubblesort(int arr[],int r, int c)
{
    if (r == 0)
    {
        return;
    }
    if (c < r)
    {
        if(arr[c]>arr[c+1]){
            swap(arr[c],arr[c+1]);
        }
        bubblesort(arr,r, c + 1);
    }
    else
    {
        bubblesort(arr ,r- 1, 0);
    }
}
int main()
{
    ll n;
    int arr[]={1,2,5,6,3};
    bubblesort(arr,5, 0);
    for (int i = 0; i <5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}