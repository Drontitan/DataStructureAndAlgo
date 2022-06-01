
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(int n)
{
    cout << n << endl;
     if(n<5){
         print(n+1);
     }
     // if we didn`t stop it will lead to stackoverflow error 
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}

// all this using the stack memory like
// when the function is finished the execution it is been remoaved from the stack


// the function repeat the it self repeatedly  and the solve the more complex problem eassily


//***space complexity is n