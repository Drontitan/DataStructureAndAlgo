#include<bits/stdc++.h>
using namespace std;

class DSU{
    public: 
 
     int *parent = new int[100005];
     void setparent(){
     for(int i=0;i<100005; i++)parent[i]=i;
     }
    //  void print(){
    //     for(int i=0 ;i <100 ;i++)cout<<parent[i]<<" ";
    //     cout<<endl;
    //  }
    // void print(string str){
    //     cout<<str;
    // }
    int findset(int a){
        if(parent[a]==a)return a;
        
        return parent[a] = findset(parent[a]);
    }
    
    void unionset(int x , int y ){

      
         int s1 = findset(x);
         int s2 = findset(y);
         
         if(s1!=-s2){

             parent[s1]=s2;
         }
         
    }

    bool sameset(int u ,int v){
    
        int s1=findset(u);
        int s2=findset(v);

        if(s1==s2)return true;
        else return false;

    }
};
string str;
vector<bool> hello(vector<vector<int>>&querry)
{
            
    DSU check;
    check.setparent();

    vector<bool>ans;
    for(auto ele: querry){
        //    str+="elel[0]";     
        if(ele[0]==1){
            check.unionset(ele[1],ele[2]);
        }
        else{
            if(check.sameset(ele[1],ele[2]))ans.push_back(true);
            else ans.push_back(false);
            
        }
    }
    // check.print();

    return ans;
    
}


int main(){

    vector<vector<int>>querry;
    int n;
    cin>>n;
    for(int i=0;i <n ;i++){
        int a,b,c;
        cin>>a>>b>>c;
        querry.push_back({a,b,c});
    }
    // for(auto ele: querry)cout<<ele[0]<<" "<<ele[1]<<" "<<ele[2]<<endl;
    vector<bool>ans;
    ans=hello(querry);
    for(auto ele:ans)cout<<ele<<" ";
    cout<<str<<endl;
    cout<<endl;
    

}