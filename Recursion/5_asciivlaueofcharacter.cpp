#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void subsequnceascii(string p,string up){

     if(up.empty()){
         cout<<p<<endl;
         return;
     }
    char ch =up.at(0);

    subsequnceascii(p+ch,up.substr(1));
    subsequnceascii(p+(ch+0),up.substr(1));
// }
int main(){
    char c='a';
    cout<<(char)(c+1);
    return 0;
}