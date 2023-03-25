#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include<bits/stdc++.h>
using namespace std;


class DSU{
    public :
      int *parent = new int[100005];
     void setparent(){
     for(int i=0;i<100005; i++)parent[i]=i;
     }

    
    int findset(int x){
        if(parent[x]==x)return x;
        return parent[x]=findset(parent[x]);
        
    }
    
    void unionset(int u , int v){
        int s1=findset(u);
        int s2 = findset(v);

          if(s1!=s2){
              parent[s1]=s2;
        }
    }
    
    
};
int makeConnected(int n, vector<vector<int>>&connections) {
    DSU solve;
    solve.setparent();
    for(auto ele: connections){
        solve.unionset(ele[0],ele[1]);
    }
    int count =0;
    for(int i=0; i<n ;i++){
        if(solve.findset(i)==i)count++;
    }
    return count;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec;
    for(int i=0 ;i< m;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }

    cout<<makeConnected(n,vec)-1<<endl;
 
    
    return 0;
}