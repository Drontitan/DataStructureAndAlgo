#include <stdio.h>
struct book{
char name[20];
float price;
int pages;

};
int main(){
    struct book b[] =
    {
        {"dssvfdg", 598, 56456},
        {"dssvfdg", 435.25, 56456}, {"dssvfdg", 350.50, 56456}};
        int i ;

     float x=b[0].price;
     for (int i = 0; i < 3; i++)
     {
         if(x>b[i].price)
         x=b[i].price;
     }
     printf("/n%.2f",x);
     return 0;
}