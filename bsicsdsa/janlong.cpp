#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


 
int main()
{
    ll n;
    cin>>n;
    while(n--){
      ll a,b;
      cin>>a>>b;
      if((a*3)<b){
          cout<<"NO"<<endl;
      }
      else if((b%3)==0){
             int ans=b/3;
             if(ans<=a){
                 cout<<"YES"<<endl;
             }
      }
      else if(a*3>b) {
          if(((a*3)-b)<=2){
              cout<<"NO"<<endl;
          }
        else if(((a-1)*3)>b){
        if((((a-1)*3)-2)==b){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
      }
      }
      else {
          cout<<"YES"<<endl;
      }
    }
    return 0;
}