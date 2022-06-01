#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
 int maximum(int a[],int n){
     int max = INT_MIN;
     for (int  i = 0; i < n; i++)
     {
         if(max<a[i]){
             max=a[i];
         }
     }
     return max;
 }
void countsort(int *a ,int n){
    int i,j;
    // find the maximum element in a 
    int max=maximum(a,n);
    // create the count array 
    int * count= (int* )malloc((max+1 )*sizeof(int));
    // initialise the element to 0
    for ( i = 0; i < max+1; i++)
    {
        count[i]=0;
    }
    // increment the index in the count array
    for ( i = 0; i < n; i++)
    {
        count[a[i]]=count[a[i]]+1;
        
    }
    i=0;// counter for count array 
    j=0;// counter for given array a

    while(i<=max){
      if(count[i]>0){
          a[j]=i;
          count[i]=count[i]-1;
          j++;
      }
      else{
          i++;
      }
    }
    

}
int main(){
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countsort(A,n);
    printArray(A, n);
    return 0;
    return 0;
}