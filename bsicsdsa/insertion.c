#include <stdio.h>
#include <stdlib.h>

void display(int arr[] , int n){

    // traversal
for (int  i = 0; i<=n ; i++)
{ 
           printf("%d ",arr[i]);
}
      printf("\n");
}
 int  indinsertion(int arr[], int size, int element, int capacity , int index)
 { 
     // code for insertion 
             if(size>=capacity){
                 return -1;
             }
             for (int  i=size-1; i >= index; i--)
             {
                 arr[i + 1]=arr[i] ;
             }
             arr[index]=element;
             return 1;
   }
int main(){
int arr[100] ={7,8,12,27,88};
int size =4 , index =3, element =45;
display(arr ,size);
size+=1;
indinsertion(arr, size, element ,100,index ); 
display(arr ,size);
    return 0;
}