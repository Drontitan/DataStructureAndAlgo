#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<pair<int,int>>vec;
        vector<int>vis(a+1,0);
        vector<int>ans;
        for(int i=0 ;i<b;i++){
            int x,y;
            cin>>x>>y;
            vis[x]=1;
            vec.push_back({x,y});
        }
         sort(vec.begin(), vec.end(), sortbysec);
         int j=1;
        for(auto ele :vec){
            if(j>a)break;
             if(ele.second==j)ans.push_back(ele.first);
             else if(!vis[i]){
                 ans.push_back(i);
                 vis[i]=1;
             }
             else ans.push_back(-1);
             j++;
         }
        for(auto ele:ans)cout<<ele<<" "<<endl;
         
    }
    return 0;
}