#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
subset  using the bit mask
here 
3 
2 4 5 
now we know there are 2^n subset so 
we will go from  0  to 2^n-1;

0 - 0000 - [] 
1 - 0001 - [2] at that is the element present so push that in to the array  **mask&(1<<i)**
2 - 0010 - [4]
3 - 0011 - [2,4]
4 - 0100 - [5]
5 - 0101 - [2,5]
6 - 0110 - [4,5]
7 - 0111 - [2,4,5]

*/

 vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    int subset = (1<<n);
    vector<vector<int>>subsets;
    for (int mask = 0; mask<subset; ++mask)
    {
        vector<int>subset;
        for (int i = 0; i <n; ++i)
        {
            if((mask & (1<<i))!=0)subset.push_back(nums[i]);
        }
        subsets.push_back(subset);
    }
    return subsets;
 }
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    auto print_subset = subsets(vec);
    for(auto ele : print_subset){
        for(auto i :ele){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}