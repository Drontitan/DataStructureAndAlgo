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
void linkedlistmerge(struct node *ptr,struct node *temp){
     struct node *newnode = (struct node *)malloc(sizeof(struct node));
       struct node *dummy =newnode;
     while (ptr!= NULL && temp!=NULL)
    {   
        if(ptr->data>temp->data){
            dummy->next=ptr;
            ptr=ptr->next;
            dummy=dummy->next;
        }
        else{
            dummy->next=temp;
             temp=temp->next;
             dummy=dummy->next;
        }
    }
    while (ptr!= NULL){
            dummy->next=ptr;
            ptr=ptr->next;
            dummy=dummy->next;
    }
    while (temp!= NULL){
             dummy->next=temp;
             temp=temp->next;
             dummy=dummy->next;
    }
    linkedlisttraversel(newnode);
}
    int main()
    {
        struct node *head1;
        struct node *second1;
        struct node *third1;
        struct node *fourth1;
        // allocate memory  for the nodes in the linked the list in heap
        head1 = (struct node *)malloc(sizeof(struct node));
        second1 = (struct node *)malloc(sizeof(struct node));
        third1 = (struct node *)malloc(sizeof(struct node));
        fourth1 = (struct node *)malloc(sizeof(struct node));
        head1->data=1;
        head1->next=second1;
        second1->data=2;
        second1->next=third1;
        third1->data=13;
        third1->next=fourth1;
        fourth1->data=12;
        fourth1->next=NULL;
        struct node *head;
        struct node *second;
        struct node *third;
        struct node *fourth;
        // allocate memory  for the nodes in the linked the list in heap
        head = (struct node *)malloc(sizeof(struct node));
        second = (struct node *)malloc(sizeof(struct node));
        third = (struct node *)malloc(sizeof(struct node));
        fourth = (struct node *)malloc(sizeof(struct node));
        head->data=5;
        head->next=second;
        second->data=10;
        second->next=third;
        third->data=45;
        third->next=fourth;
        fourth->data=50;
        fourth->next=NULL;
        linkedlistmerge(head1,head);
        // linkedlisttraversel(head);
        return 0;
    }