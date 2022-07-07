#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// her we have to find the number of lis are there in the array
// here we have took the count array and the dp array 
// in the dp array the length of the lis is store
// in count array the count of the length present in the dp is store
 
int main(){
    vector<int>vec ={ 1,3,5,4,7};
    int n=vec .size();

    vector<int> dp1(n, 1),count(n,1);

    // for the increasing part 
    int maxi=1;
    for (int i = 0; i < n; i++)
    {

        for (int prev = 0; prev < i; prev++)
        {
            if (vec[i]>vec[prev] && 1+dp1[prev]>dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
                // inherit
                count[i]=count[prev];
            }
            else if(vec[i]>vec[prev]&&1+dp1[prev]==dp1[i]){
                // increase 
                count[i]+=count[prev];
            }
        }
        maxi= max(maxi,dp1[i]);
    }
    int number=0;
    for(int i =0 ;i<n;i++){
        if(dp1[i]==maxi)number+=count[i];
    }
    cout<<number<<endl;
    return 0;
}