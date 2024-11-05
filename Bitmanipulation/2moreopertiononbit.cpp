#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void  printbinary(int n){
    for(int i=10;i>=0;--i){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
int main()
{
    for (int i = 0; i <8; ++i)
    {
        // printbinary(i);
        // odd number
        // if(i&1)cout<<"odd"<<endl;
        // else cout<<"even"<<endl;
    }
        // multiply by two (n<<1) n*2^1;
        // divide by two (n>>1)n/2^1;

        // for lower case to uppercase and vise -versa

        // binary for the capital letters
        // for(char c ='A';c<='Z';++c){
        //     cout<<c<<endl;
        //     printbinary(int(c));
        // }
        
        // // binary for the small case letters
        //   for(char c ='a';c<='z';++c){
        //     cout<<c<<endl;
        //     printbinary(int(c));
        // }
        // char A ='A';
        // char smalla = A|(1<<5);
        // cout<<smalla<<endl;
        // cout<<char(smalla& ~(1<<5))<<endl;
        // cout<<char('C' | ' ')<<endl;// lowercase conversion
        // cout<<char('d' & '_')<<endl;// uppercase conversion

        // printbinary(59);
        // int a=59;
        // int i=4;  //  convertig i bit of lsb unset
        // int b=(a & (~((1<<(i+1))-1)));
        // // int b=(a&(1<<(i+1)));
        // printbinary(b);

        // int c= (a & ((1<<(i))-1));
        // printbinary(-1);

        /********/
        // check if the number is the power fo the two 
        int n=100;
        if(!(n&(n-1)))cout<<"YEs"<<endl;
        // else cout<<"yes"<<endl;
    return 0;
}