#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
let say there are n fruits 
Appel-0
Banana-1
graps-2
watermelon-3
mango-4

so there are 3 friends and they carry these fruits we hava to find the intersection of these fruits 
they have

1 - 0 ,2   so we can represent it in binary as setting the bit at that position - 00101
2-  2 ,3   -00110
3-  1 ,2   -00110

and we can take and(&) to calculate the no. of intersection

limitation:- no of ele can be usigned int 32 ||  unsigned long long 64 max size 64 not more
than that 

*/
void  printbinary(int n){
    for(int i=10;i>=0;--i){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int>masks(n,0);
   
    for (size_t i = 0; i <n; ++i){
    int num_ofworkers;
    cin>>num_ofworkers;
    int mask=0;
    for (int j = 0; j <num_ofworkers; ++j)
    {
       int day;
       cin>>day;
       mask|=(1<<day);
    }
    masks[i]=mask;
    }
    // for(auto ele :masks){
    //     cout<<ele<<endl;
    //     printbinary(ele);
    // }
    int maxdays=0;
       for (size_t i = 0; i <n; ++i){
            for (int j = i+1; j <n; ++j){
            int intersection =masks[i]&masks[j];
            int commondays = __builtin_popcount(intersection);
             maxdays=max(maxdays,commondays);
    }
       }
       cout<<maxdays<<endl;
    return 0;
}