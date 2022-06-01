#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum=0;
int reversenumber(int n){
    
   if(n==0){
       return 0;
   }
   int rem =n%10;
   sum=sum*10+rem;
   reversenumber(n/10);
   return sum;
}
int main(){
    int n;
    cin>>n;
    int a=  reversenumber(n);
    if(sum==n){

        cout<<"yes it is a palllindrome";
    }
   cout<<a<<endl;
    return 0;
}