#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int lenghtofstring(string str,int i){

    if(str[i]=='\0'){
        return i;
    }
     return  lenghtofstring( str,i+1);
}
int main(){
    string str;
    cin>>str;
    cout<<lenghtofstring(str,0);
    return 0;
}