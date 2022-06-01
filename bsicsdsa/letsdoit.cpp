#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin>>n;
    while(n--){
        string a;cin>>a;
        string b;cin>>b;int count=0,flag=0;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        if(a.length()<=b.length()){
           for (int i = a.length()-1;i>=0; i--)
            {
               if(a[i]=b[i]){
                 b.pop_back();
                 a.pop_back();
               }
               else{
                   b.pop_back();
                   flag++;
                //    i++;
               }
                
            }
      
        }
        cout<<""<<b<<endl;;
              if(a.length()==0){
                b.clear();
                
            }
        if(b.length()==a.length()){
            cout<<flag<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}