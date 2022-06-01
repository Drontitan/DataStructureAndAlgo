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

void removeduplicates(struct node *node){
     struct node *ptr=node;

     while (ptr->next != NULL)
    {   
        if(ptr->data==ptr->next->data){
           ptr->next=ptr->next->next;
        }
        else {
            ptr=ptr->next;
        }

    }
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
        second->data=90;
        second->next=third;
        third->data=90;
        third->next=fourth;
        fourth->data=26;
        fourth->next=NULL;
        removeduplicates(head);
        linkedlisttraversel(head);
        return 0;
    }