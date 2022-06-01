#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SORT(name) sort(name.begin(), name.end())

void bitwiseComplement(int n) {
        
    char binary[32];
    for(int i=10;i>=0;i--){
        int k=n >> i;
        if(k&1){
           binary[i]='1';
        }
        else{
          binary[i]='0';
        }
    }
    for (int i = 0; i <10; i++)
    {
        cout<<binary[i]<<"";
    }
    cout<<"\n";
   cout<<stoi(binary,0,2);
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   bitwiseComplement(7);
    return 0;
}