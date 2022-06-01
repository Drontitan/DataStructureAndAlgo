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
struct  node *insertatbegining(struct node* head ,int data){
    struct node * ptr = (struct node*)malloc (sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//  case 3;

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
// case 4
struct  node *insertafter(struct node* head,struct node* prevnode ,int data){
    struct node * ptr = (struct node*)malloc (sizeof(struct node));
 
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
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

    int main()
    {
        struct node *head;
        struct node *second;
        struct node *third;
        struct node *fourth;
        // allocate memory  for the nodes in the linked the list in heap
        // allocate memory  for the nodes in the linked the list in heap
        head = (struct node *)malloc(sizeof(struct node));
        second = (struct node *)malloc(sizeof(struct node));
        third = (struct node *)malloc(sizeof(struct node));
        fourth = (struct node *)malloc(sizeof(struct node));
        // link first and second nodes
        head->data = 7;
        head->next = second;
        // link  second and third  nodes
        second->data = 11;
        second->next = third;
        // link third and fourth   nodes
        third->data = 18;
        third->next = fourth;
        // terminate the list at the fourth  node
        fourth->data = 66;
        fourth->next = NULL;

        printf("linked list before insertion \n");
        linkedlisttraversel(head);
        // head = insertatbegining(head, 56);
        // head = insertinbetween(head, 56, 1);
        // head = insertatend(head, 56);
        head = insertafter(head,second , 45);
        printf("linked list after insertion \n");
        linkedlisttraversel(head);
        return 0;
    }