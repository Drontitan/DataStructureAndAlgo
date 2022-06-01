#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printbinary(int num){
  
  for(int i=10;i>=0;--i){
      cout<<((num>>i)&1);
  }
  cout<<endl;
}


int main()
{ 
    printbinary(9);
    int a=9;
    int i=1;
    if((a & (1<<i) )!=0)cout<<"set"<<endl;
    else cout<<"notset"<<endl;

    //  if we want to set the bit then 
    printbinary(a | (1<<i));

    // if we want to unseet the bit in the number then
    // first we need to inverrt the number 
    // printbinary(~a);
    printbinary(a & ~(1<<i));

    // how to toggle the bit
    printbinary(a ^ (1<<2));


    // count fo the set bit 
    int count=0;
    for(int i=31;i>=0;--i){
         if((a & (1<<i) )!=0)count++;
    }
    cout<<count<<endl;

    cout<<__builtin_popcount(a);// for int 
    cout<<__builtin_popcountll(a);// for long long
    return 0;
}

