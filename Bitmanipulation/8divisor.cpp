#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    int n;
    cin>>n;
    int sum=0,count=0;
    // for (int i = 0; i <sqrt(n); i++)
    for (int i = 1; i*i<=n; i++){   //  same concept in the prime number also 
        if(n%i==0){
            cout<<i<<" "<<n/i<<endl;
            count+=1;
            sum+=i;
            if(n/i!=i){
                count+=1;
                sum+=n/i;
            }
            
        }
    }
    cout<<count<<" "<<sum<<endl;
    return 0;
}