#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


vector<vector<int>> subset(vector<int>&arr){
    vector<vector<int>>outerlist;

    for (int num:arr)
    {
        int n=outerlist.size();
        for (int i = 0; i <n; i++)
        {
            vector<int>internal;
            internal.push_back(num);
            outerlist.insert(outerlist.begin(),internal.begin(),internal.end());
        }
        
    }
    
}

int main(){
     vector<int>arr={1,2,3};
    vector<vector<int>>ans=subset(arr);
    for (vector<int>list:ans)
    {
        cout<<list;
    }
    
     return 0;
}