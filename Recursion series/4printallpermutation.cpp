#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//TC - O(N!)*N
//SC - O(N) +O(N)
void solve(vector<int>&vec,vector<int>&ans,int fre[]){
    if(ans.size()==vec.size()){
        for(auto ele:ans)cout<<ele<<" ";
        cout<<endl;
        return ;
    }

    for(int i=0;i <vec.size();i++){
        if(!fre[i]){
        ans.push_back(vec[i]);
        fre[i]=1;
        solve(vec,ans,fre);
        fre[i]=0;
        ans.pop_back();
        }
    }
}

//TC- O(N!)*O(N)
// Sc-O()
void solve2(vector<int>&vec,int ind){
    if(ind==vec.size()){
        for(auto ele:vec)cout<<ele<<" ";
        cout<<endl;
        return;
    }

    for(int i=ind;i<vec.size();i++){
       swap(vec[ind],vec[i]);
        solve2(vec,i+1);
       swap(vec[ind],vec[i]);
        
    }
}

int main(){
    vector<int>vec={1,2,3};
    vector<int>ans;
    int fre[vec.size()];
    for(int i=0 ;i<vec.size();i++)fre[i]=0;
    solve(vec,ans,fre);
    // solve2(vec,0);
    return 0;
}