#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    int n;
    cin>>n;
    vector<ll>vec;
    map<char,char>mp;
    string str;
    cin>>str;
    for(int i=0;i<26;i++){
     mp['a'+i]=str[i];   
    }
    for(auto ele:mp)cout<<ele.first<<" "<<ele.second<<endl;
    vector<string>temp;
    while(n--){
        string ans;
        string res;
        cin>>res;
        
        for(auto ele:res){
            if(ele=='_'){
                ans+=" ";
                continue;
            }
            if(mp.find(ele)==mp.end() && mp.find(tolower(ele))!=mp.end() ){
                // cout<<mp[tolower(ele)]<<"*"<<endl;
                ans+=toupper(mp[tolower(ele)]);
            }
            else if(mp.find(ele)!=mp.end()){
                ans+=mp[ele];
            }
            else{
                ans+=ele;
            }
            // cout<<ans<<endl;
    
        }
        temp.push_back(ans);
    }

    for(auto ele:temp)cout<<ele<<endl;


    return 0;
}