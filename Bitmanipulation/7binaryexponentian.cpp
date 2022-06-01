#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M =1e9+7;

/*
if the  power of number is even 
12
2^12 - 2^6 * 2^6
2^6  - 2^3 * 2^3   //  for odd power we 1st  break it in to even powet then compute further
2^3  - 2 *  2^1
2^1  - 2  * 2^0

if the power of number is odd
7
3^7  -  3 * 3^6
3^6  -  3^3 * 3^3
3^3  -  3 * 3^2
3^2  -  3^1* 3^1
3^1  -  3 * 3^0
*/

// recursive method
// (A^B)%M 

int binaexponentrecur(int a,int b){
    if(b==0)return 1;
    int res=binaexponentrecur(a,b/2);
    if(b&1){  // for  odd 
        return (a* ((res *1ll*res)%M))%M;
    }
    return( res * 1ll * res)%M;
} 

// iterative method 
int binaryiterative(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*1ll*a)%M;
        }
        a=(a*1ll*a)%M;
        b>>=1;
    }
    return ans;
}

//  b<10^9;
// b<10^18
int binaexponentrecurbbdahai(int a,long long b){
    if(b==0)return 1;
    int res=binaexponentrecur(a,b/2);
    if(b&1){  // for  odd 
        return (a* ((res *1ll*res)%M))%M;
    }
    return( res * 1ll * res)%M;
} 

int main(){
    cout<<binaryiterative(2,3);
    return 0;
}



