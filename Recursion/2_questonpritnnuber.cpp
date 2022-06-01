#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printnumber(int n){

    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printnumber(n-1);
}
void printnumberrev(int n){
     
     if(n==0){
         return ;
     }
     printnumberrev(n-1);
     cout<<n<<endl;
}
void funboth(int n){
     
}
int main(){
    int n;
    cin>>n;
    printnumber(n);
    printnumberrev(n);

        return 0;
}