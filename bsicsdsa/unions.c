#include <stdio.h>
union data{
    char name[20];
    int rollnumber;

};
int main(){
    union data data;
    printf("the size of data is %u\n",sizeof(data));
    printf("the size of data is %u\n",sizeof(data.rollnumber));
    printf("the size of data is %u\n",sizeof(data.name));
    return 0;
}