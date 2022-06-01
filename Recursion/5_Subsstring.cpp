#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// void subsequnce(string p,string up){

//      if(up.empty()){
//          cout<<p<<endl;
//          return;
//      }
//     char ch =up.at(0);

//     subsequnce(p+ch,up.substr(1));
//     subsequnce(p,up.substr(1));
// }
vector<string> subsequnce(string p,string up){

    if(up.empty()){
        vector<string>str;
        str.push_back(p);
        return str;
     }
    char ch =up.at(0);
    vector<string> left = subsequnce(p + ch, up.substr(1));
    vector<string> right = subsequnce(p , up.substr(1));
     left.insert(left.begin(),right.begin(),right.end());
     return left ;
}

int main()
{

    vector<string> ans = subsequnce( "","abc");
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
