#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void subssequence(vector<int>&vec,vector<int>&curr,int index){
  
   if(index==vec.size()){
       for(auto ele:vec)
           cout<<ele<<" ";
    cout<<endl;
           return;
   }
    for(int i =index;i<vec.size();i++){
    swap(vec[index],vec[i]);
    subssequence(vec,curr,index+1);
      swap(vec[index],vec[i]);;
    }
    

}
int main(){
    vector<int>vec={1,2,3};
    vector<int>ans;
    sort(vec.begin(),vec.end());
    subssequence(vec,ans,0);
    return 0;
}