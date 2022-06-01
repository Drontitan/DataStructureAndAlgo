#include <stdio.h>


void fun(int *p){
    int k;
    for (k = 0; k<3; k++)
    {
        *(p+k)+=1;
    }
    
}
int main(){
    int i,arr[]={6,2,1,9,3,4,9,};
   int *ip=arr+3;
    fun(ip);
    for ( int i = 0; i < 7; i++)
    {
       printf("%d",arr[i]);
    }
    
    return 0;
}