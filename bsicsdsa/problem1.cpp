#include <iostream>
using namespace std;
// find the time coplexity fo the followig program
void func1(int array[] ,int length){
    int sum =0;
    int product=1 ;   //f1
    for (int i = 0; i < length; i++)
    {
        sum+=array[i];      // f2
    }
    for (int  i = 0; i < length; i++)
    {
        product *=array[i];      /// f3
    }
    
//  total time = f1+f2n+f3n
// total time complexity =  Big of n length
}
int main(){
    int arr[] ={3,5,7};
    func1(arr,3);
    return 0;
}