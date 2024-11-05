#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// int countNums(int x, int y, int n)
// {
//     if (x == 0 || y == 0) {
//         return 0; 
//     }

//     int divX = n / x;
//     int divY = n / y;
//     int lcm = (x * y) / __gcd(x, y);
//     int divLcm = n / lcm;
//     int divXorY = divX + divY - divLcm;
//     int divXnotY = divXorY - divY;
    
//     return divXnotY;
// }

void findmultiple(int num, int n , set<long long int>& st) {

    long long int product =  num;
    while(product <= (long long int)n){
      st.insert(product);
      product*=num;
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
     int n ;
     cin>>n;
     string str;
     cin>>str;
    //  cout<<str<<endl;
     int zero =0, one =0;
     for(auto ele:str){
        if(ele=='0')zero++;
     }
     one  = n-zero;
     int ans=0;
     set<long long int>st;
     if(zero==0 ||  one ==0){
        ans+=(n/2);
        if(zero!=0){
            findmultiple(zero,n,st);
            ans+=st.size();
        }
        else if(one!=0){
            findmultiple(one,n,st);
            ans+=st.size();
        }
     }
     else{

     for(int i=min(one,zero);i<=n;i++){
        if(i==zero || i==one)st.insert(i);
        else{
        // if(st.count(i-zero)>1 || st.count(i-one)>1)continue;
        if((i-zero)%zero==0 || (i-zero)%one==0)st.insert(i-zero);
        else if ((i-one)%zero==0 || (i-one)%one==0)st.insert(i-one);
        }
        }
        ans+=st.size();
      }
     cout<<ans<<endl;
    }
    return 0;
}