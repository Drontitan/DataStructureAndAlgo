#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int a=3,b=4;
    // properties
    // x^x=0 ,x^0=x
    // x^Y^Z=y^x^z=Z^X^Y  assosiative property
    /*****************/
    // swap operation
    //  a=a^b;
    //  b=b^a;
    //  a=a^b;
    //  cout<<a<<" "<<b<<endl;


     /*given an array of n interger all the integer have even count except one integer 
     print the that integer  */

     int ans=0;
     vector<int>vec={1,2,1,3,3,4,4,5,5,4,4};
     for(auto ele : vec){
         ans^=ele;
     }
     cout<<ans;
    return 0;
}