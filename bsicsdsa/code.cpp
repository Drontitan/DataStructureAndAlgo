#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int a;
    cin>>a;
    while(a--){
           int n,m,l;
           cin>>n>>m>>l;
           int rem=0;
           int ans=0;
           rem=m%(l+n-1);
           for (int i = 0; i <n ; i++)
           {
               if(rem<=(l+n-2)){
                   cout<<m
               }
           }
           cout<<m<<endl;
 }
        
    
    return 0;
}