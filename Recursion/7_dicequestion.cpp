#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void posiibleway(string p,int target){
     
    if(target==0){
        cout<<p<<endl;
        return;
    }
    for (int i = 1; i<=target; i++)
    {   
        posiibleway(p+char(i+'0'),target-i);
    }

}

int main(){
    posiibleway("", 4);
     return 0;
}