#include <iostream>
using namespace std;
void func1(int n)
{
    int sum = 0;      //k1
    int product = 1; //f1
    for (int i = 0; i < n; i++)
    {
                                               
    for (int j = 0; j < n; j++)
    {
        cout<<i<<j<<endl;              //k2n^2
    }
    }
}
    int main()
    {
                      // total time complexity = big of n^2
        return 0;
    }