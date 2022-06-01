#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool sumofdigit(int n,int i){

   if(n<=2)return (n==2)? true:false;
   if(n%i==0)return false;
   if (i * i > n)
        return true;
   return sumofdigit(n,i+1);

}

 int main(){

    cout<<sumofdigit(13,2);
    return 0;
}
