#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// void stringpat(string p,string up){
//     if(up.empty()){
//         cout<<p<<endl;
//         return;
//     }
//    int digit= up.at(0)-'0';
//    for (int i = (digit-1)*3; i <digit*3; i++)
//    {
//        char ch=char('a'+i);
//        stringpat(p+ch,up.substr(1));
//    }
   
// }
int stringpatcount(string p,string up){
    if(up.empty()){
        return 1;
    }
    int count=0;
   int digit= up.at(0)-'0';
   for (int i = (digit-1)*3; i <digit*3; i++)
   {
       char ch=char('a'+i);
      count=count+stringpatcount(p + ch, up.substr(1));
   }
   return count;
}
// vector<string> phonepat(string p, string up)
// {

//     if (up.empty())
//     {
//         vector<string> str;
//         str.push_back(p);
//         return str;
//     }
//     int digit = up.at(0) - '0';
//     vector<string>ans;
//     for (int i = (digit - 1) * 3; i < digit * 3; i++)
//     {
//         char ch = char('a' + i);
//         ans.insert(ans.begin(),stringpat(p + ch, up.substr(1)));
//     }
//   return ans;
// }
int main(){
    // stringpat("","12");
    cout<<stringpatcount("", "12");
    // vector<string> ans = phonepat("", "12");
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
     return 0;
}