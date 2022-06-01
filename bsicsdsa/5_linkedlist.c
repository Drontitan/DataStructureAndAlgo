#include <stdio.h>
#include <stdlib.h>


struct  node
{
    int data;
    struct node * next;
};

void linkedlisttraversel(struct node * ptr){
    while(ptr!=NULL){
    printf("element : %d \n",ptr->data);
    ptr =ptr->next;

    }
}
int main(){
    struct node*head;
    struct node*second;
    struct node*third;
    struct node*fourth;
    // allocate memory  for the nodes in the linked the list in heap 
    // allocate memory  for the nodes in the linked the list in heap 
    head = (struct node* ) malloc(sizeof( struct node));
    second = (struct node* ) malloc(sizeof( struct node));
    third  = (struct node* ) malloc(sizeof( struct node));
    fourth  = (struct node* ) malloc(sizeof( struct node));
     // link first and second nodes
     head->data=7;
     head->next=second;
     // link  second and third  nodes
     second->data=11;
     second->next=third;
     // link third and fourth   nodes
     third->data=18;
     third->next=fourth;
     // terminate the list at the fourth  node 
     fourth->data=66;
     fourth->next=NULL;
    
     linkedlisttraversel(head);
    return 0;
}