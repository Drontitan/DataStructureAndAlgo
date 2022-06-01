#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *head){
    struct node *ptr =head;
    // printf(" elelment is %d \n", ptr->data);
    // ptr = ptr->next;
    // while(ptr!=head ){
    //     printf(" elelment is %d \n",ptr->data);
    //      ptr=ptr->next;

    // }
    // they have the next method do that 
   do{
        printf(" elelment is %d \n",ptr->data);// the most appropriate way of doing the job
         ptr=ptr->next;
   }
   while (ptr != head);
}

struct node* insertatfirst(struct node * head, int data ){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p =head->next;
    while(p->next!=head){
        p=p->next;
    }
  // at this point the p points to the last node of the cicular linked list 
  p->next=ptr;
  ptr->next=head;
  head=ptr;
  return head;
}
int main(){
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
    head->data = 4;
    head->next = second;
    // link  second and third  nodes
    second->data = 3;
    second->next = third;
    // link third and fourth   nodes
    third->data = 6;
    third->next = fourth;
    // terminate the list at the fourth  node
    fourth->data = 1;
    fourth->next = head;
    printf("circular linkedlist before Addition\n");
    linkedlisttraversal(head);

    head = insertatfirst(head, 67);
    printf("circular linkedlist after Addition\n");
    linkedlisttraversal(head);
    return 0;
}

