#include<stdio.h>

int linearsearch(int arr[],int size, int element){
    for (int  i = 0; i < size; i++)
    {
        if (arr[i]==element){
            return i;
        }
    
    }
    return -1;
}
int binarysearch(int arr[],int size, int element){
    int mid , low, high ;
    low=0;
    high =size-1;
    //start searching    keep searching until low and high converges
    while(low<=high){
    mid =(low+high)/2;
     if(arr[mid]==element){
         return mid;
     }
     if(arr[mid]<element){
        low = mid+1;
     }
     else{
         high =mid-1;
     }
    }
     // searching ends
     return -1;
}
int main(){
    // unsorted fot linear search 
    //   int arr[]={1,4,6,9,7,77};
    //   int size =sizeof(arr)/sizeof(int);
    //sorted binary search 
      int arr[]={1,4,6,7,9,77};
      int size =sizeof(arr)/sizeof(int);
      int element =1;
      int searchindex = binarysearch(arr, size,element);
      printf("the element %d was found at %d ",element, searchindex);
     return 0;
}