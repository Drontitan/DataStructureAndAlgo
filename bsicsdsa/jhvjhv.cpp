#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec;
        for(int i=0;i<nums1.size();i++){
            int j=0;
            for(;j<nums2.size();j++){
                if(nums2[j]>nums1[i]){
                    vec.push_back(nums2[j]);
                    break;
                }
            }
            if(j==nums2.size()){
                vec.push_back(-1);
            }
        }
        return vec;
    }
int main()
{
    vector<int>vec1={4,1,2};
    
    vector<int>vec2={1,3,4,2};
    vector<int>ans=nextGreaterElement(vec1,vec2);
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<"";
    }
    
    return 0;
}