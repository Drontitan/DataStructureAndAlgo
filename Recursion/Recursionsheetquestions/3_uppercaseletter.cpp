#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char finfuppercase(string a,int index){
           
           if(a[index]=='\0'){
             return 0;
           }
           if (isupper(a[index]))
           {
             return a[index];
           }
          return finfuppercase(a,index+1);
}
int main(){
    string str;
    cin>>str;
   cout<<finfuppercase(str,0);
     return 0;
}