#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string remove(string str,int i){
        if(str[i]=='\0'){
          return str;
        }
       if(str[i]==str[i+1]){
           str[i+1]=str[i+2];
       }
    return remove(str, i+1);
}
int main(){
    string str;
    cin>>str;
  cout<<remove(str,0);
    return 0;
}