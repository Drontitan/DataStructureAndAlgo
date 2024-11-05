#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 string removeReverse(string s) {
      map<char,int>mp;
      for(auto ele: s)mp[ele]++;
      int n = s.size();
      bool flag=true;
      int i=0, j=n-1;
      vector<int>visi(n,0);
      while(i<=j){
          if(mp[s[i]]>1 && flag){
              mp[s[i]]--;
              visi[i]=1;
              i++;   
              flag=false;
          }
          else if(mp[s[i]]==1 and flag)i++;
          else if(mp[s[j]]>1 && !flag){
              mp[s[j]]--;
              visi[j]=1;
              j--;
              flag=true;
          }
         else if(mp[s[j]]==1 and !flag)j--;
      }
    //   for(auto ele:visi)cout<<ele<<" ";
    //   cout<<endl;
      string str;
      for(int i=0 ;i <n;i++){
          if(!visi[i] && flag)str+=s[i];
      }
      
      for(int i=n-1;i >=0 ;i--){
          if(!visi[i] && !flag)str+=s[i];
      }
      return str;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        cout<<removeReverse(str)<<endl;
    }
    return 0;
}