#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    int n;
    cin>>n;
     vector<int>vec;
     for (int i =2; i <=n;++i)
     {
         while(n%i==0){
             vec.push_back(i);
             n/=i;
         }
     }
     for(auto ele : vec){
         cout<<ele<<endl;
     }
    return 0;
}