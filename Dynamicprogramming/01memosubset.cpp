#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())
bool t[50][50];
void memoset(){
    memset(t,false,sizeof(t));
}
bool kanpsack(int arr[], int sum, int n)
{
    if(sum==0){
        return true;
    }
    if(n==0||sum<0){
        return false;
    }
    if(t[n][sum]!=false){
        return true;
    }
            if (arr[n - 1] <= sum)
            {
                return t[n][sum] = kanpsack(arr, sum - arr[n - 1], n - 1) ||kanpsack(arr, sum, n - 1);
            }
            else
            {
               t[n][sum]=kanpsack(arr, sum, n - 1);
            }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[4] = {4, 3, 7, 10};
    int sum = 11;
    int n = 4;
    memoset();
    cout << kanpsack(arr, sum, n);
    return 0;
}
