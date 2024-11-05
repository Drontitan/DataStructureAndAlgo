#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// subset sum1 *************
// if duplicate are not taken if taken we can modify it but the 2nd approach is better in that case
void solve(vector<int>vec,vector<int>ans,int i){
     
     if(i==vec.size()){
        int sum=0;
        for(auto ele:ans)sum+=ele;
        cout<<sum<<endl;
        return;
     }
     
     ans.push_back(vec[i]); // take and not take approach 
     solve(vec,ans,i+1);
     ans.pop_back();
     solve(vec,ans,i+1);
}





// subset sum 2*******

// return all the subset which may conatains the duplicate element but not the duplicate combination
void solveby2ndapproachmodi(vector<int>vec,vector<int>ans,int ind){
     
     
    for(auto ele:ans)cout<<ele<<" ";
    cout<<endl;

    for (int i = ind; i <vec.size(); i++)
    {
     if(i>ind && vec[i]==vec[i-1])continue;// for only for the duplicates 
     // here i!=ind means we are taking the all repetition possible made by element but not taking the next 
     // same combination made by same as we done before
     ans.push_back(vec[i]);
     solveby2ndapproachmodi(vec,ans,i+1);
     ans.pop_back();        
    }

}

int main(){
      vector<int>vec={1,1,3};
    sort(vec.begin(),vec.end());
      vector<int>ans;
      // solve(vec,ans,0);
      // solveby2ndapproach(vec,ans,0)
      solveby2ndapproachmodi(vec,ans,0);
    return 0;
}