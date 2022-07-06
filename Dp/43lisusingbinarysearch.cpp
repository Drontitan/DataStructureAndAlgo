#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here we are using the binary search 
//  ex: 1 7 8 4 5 6 -1 9
//  here the final array we get will not be then lis we are requiring but its size will be same
// as what we require

//  take 1     : -  1 7 8 now 4 is cannot be inserted as last
// replace 7 by 4  : -  1, 4 , 8 then for 5 replace the 8 
//  1 4 5 then for 6 it 6>5 
//  1 4 5 6 then for -1 
//  -1 4 5 6 then for 9  -1 4 5 6 9 size will be of size 5 

// TC - O(n*logn) 
// SC - O(n)

int main(){
    vector<int>vec={1,7,8,4,5,6,-1,9};
     int n= vec.size();
     vector<int>temp;
     int length=1;
     temp.push_back(vec[0]);
     for(int i = 1; i<n;i++){
        if(temp.back()<vec[i]){
            temp.push_back(vec[i]);
            length++;
        }
        else{
            int ind =lower_bound(temp.begin(),temp.end(),vec[i])-temp.begin();
            temp[ind]=vec[ind];

        }
     }
     cout<<length<<endl;
    return 0;
}