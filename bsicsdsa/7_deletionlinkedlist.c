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
// case 1; delting the first element from the linked list
struct node *deletefirst( struct node * head){
  struct node * ptr = head;
  head = head->next;
   free(ptr);
   return head;
}

// case 2; delting the element from the linked list from any index 
struct node *deleteatindex( struct node * head ,int index){
    struct  node *p=head;
    struct  node *q=head->next;
  for (int  i = 0; i <index-1; i++)
  {
      p=p->next;
      q=q->next;
  }
  p=p->next=q->next;
  free(q);
   return head;
}

// case 3; delting the last  element 
struct node *deletelast( struct node * head ){
    struct  node *p=head;
    struct  node *q=head->next;
   while(q->next!=NULL)
  {
      p=p->next;
      q=q->next;
  }
  p->next=NULL;
  free(q);
   return head;
}

// case 4; deleting the element from the linked list with a given value 
struct node *deleteatvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
     while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
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
    printf("linkedlist before deletion\n");
    linkedlisttraversel(head);

    // head =deletefirst(head);// for deleting first element of the linked list 

    // head =deleteatindex(head ,2);
    // head =deletelast(head );
    head = deleteatvalue(head ,18);

    printf("linkedlist after deletion\n");
    linkedlisttraversel(head);

    return 0;
}