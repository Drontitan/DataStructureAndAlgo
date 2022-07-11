#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// the roober want to steal the house and house are arranged in the circular order 
// robber can steal any house but the house should be adjacent 


int maxsubssumspace(vector<int>vec){
    int n=vec.size();
    int prev=vec[0];
    int prev2=0;
   for(int i=1; i<n;i++){
     int take= vec[i];
     if(i>1)take+=prev2;
     int notake =0+prev;
     int curr= max(take,notake);
     prev2=prev;
     prev=curr;
   }
   return prev;
}
int main(){
    vector<int>vec={9,3,4,5,6,7};
    int n=6;
    vector<int>newvec1,newvec2;
    for(int i=0;i<n;i++){
        if(i!=0)newvec1.push_back(vec[i]);// last house is adjacent of the 1st house 
    }
    for(int i=0;i<n;i++){
        if(i!=n-1)newvec2.push_back(vec[i]);
    }                                                                        
    cout<<max(maxsubssumspace(newvec1),maxsubssumspace(newvec2));
    return 0;
}