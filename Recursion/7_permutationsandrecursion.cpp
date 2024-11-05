#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void permutations(string p,string up){
    if(up.empty()){
        cout<<p<<endl;
        return ;
    }
    char ch=up.at(0);
    for (int i = 0; i <=p.size(); i++)
    {
        string f =p.substr(0,i);
        string s =p.substr(i,p.size());
        permutations(f+ch+s,up.substr(1));
    }
    
}
int permutationscount(string p,string up){
    if(up.empty()){
        return 1;
    }
    int count=0;
    char ch=up.at(0);
    for (int i = 0; i <=p.size(); i++)
    {
        string f =p.substr(0,i);
        string s =p.substr(i,p.size());
        count=count+ permutationscount(f+ch+s,up.substr(1));
    }
    return count;
    
}

int main(){
    permutations("","abc");
//    cout<< permutationscount("","abc");
     return 0;
}