
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void print4(int n)
{
    cout << n << endl;
}
void print3(int n)
{
    cout << n << endl;
    print4(n + 1);
}
void print2(int n)
{
    cout << n << endl;
    print3(n + 1);
}
void print1(int n)
{
    cout << n << endl;
    print2(n + 1);
}
void print(int n){
    cout<<n<<endl;
    print1(n+1);
}

int main(){
     int n;
     cin>>n;
     print(n);
    return 0;
}


// all this using the stack memory like 
// when the function is finished the execution it is been remoaved from the stack 