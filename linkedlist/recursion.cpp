#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversel(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}
//case 1;

struct  node *insertatend(struct node* head ,int data){
    struct node * ptr = (struct node*)malloc (sizeof(struct node));
    ptr->data=data;
    struct node * p =head;
    while (p->next!=NULL)
    {
         p=p->next;

    }
    p->next=ptr;
    ptr->next =NULL;
    return head;
}

// case 2;
struct node *insertinbetween(struct node *head, int data,int index){
    struct node * ptr = (struct node*)malloc (sizeof(struct node));
      struct node* p= head;
      int i =0;
      while (i!=index-1)
      {
          p=p->next;
          i++;

      }
      ptr->data=data;
      ptr->next=p->next;
      p->next=ptr;
      return head;
}
void recusiveaddition(int val,int index,struct node* node,struct node * pre){
         if(index==0){
          struct node * ptr = (struct node*)malloc (sizeof(struct node));
          ptr->data=val;
          pre->next=ptr;
          ptr->next=node;
          return ;
         }
        return recusiveaddition(val,--index,node->next,node);
         
}
    int main()
    {
        struct node *head;
        struct node *second;
        struct node *third;
        struct node *fourth;
        // allocate memory  for the nodes in the linked the list in heap
        head = (struct node *)malloc(sizeof(struct node));
        second = (struct node *)malloc(sizeof(struct node));
        third = (struct node *)malloc(sizeof(struct node));
        fourth = (struct node *)malloc(sizeof(struct node));
        head->data=90;
        head->next=second;
        second->data=23;
        second->next=third;
        third->data=34;
        third->next=fourth;
        fourth->data=29;
        fourth->next=NULL;
        linkedlisttraversel(head);
       recusiveaddition(56,2,head,NULL);
        linkedlisttraversel(head);
        return 0;
    }