#include <stdio.h>

struct node {
    struct node *next;
    int data;
};

struct node *indsertdata(struct node *head,int data){
   struct node *p =head;
   p->data=data;
   while(p->next !=NULL){
       p=p->next;
   }
  
   
}


int main(){  
  struct node *head= NULL;
  
   

}