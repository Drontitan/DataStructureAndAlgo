#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}
int main(){
  int n;
  printf("Enter the size of array you want \n");
  scanf("%d",&n);
  int arr[n];
  for (int i = 0; i <n; i++)
  {    

      scanf("%d", &arr[i]);
      if(arr[i]<0){
        printf("The negative value cant be entered\n");
        exit(0);
      }
  }
  int max=0;
      for (int i = 0; i <n; i++)
      {
          if(arr[i]>max){
              max=arr[i];
          }
      }
  int min=arr[0];
      for (int i = 0; i <n; i++)
      {
          if(arr[i]<min){
              min=arr[i];
          }
      }
       printf("The greatest two numbers  are: ,%d\n",max);// if you want you can direct print below in printf
       // without calculating max and directly sorting
       printf("The smallest two numbers  are: ,%d\n",min);
       bubbleSort(arr, n);
       if(n>3){
       printf("The 2nd greatest two numbers  are: ,%d\n", arr[n-2]);
       printf("The 2nd smallest two numbers  are: ,%d\n", arr[1]);
       }
       return 0;
}