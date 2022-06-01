#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void rotate(struct node **head, int k)
{
    if (k == 0)
        return;
    struct node *ptr = *head;
    int i=1;
    while (i < k && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    //  
    if(ptr==NULL){
        return;
    }
    struct node *p = ptr;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = *head;
    *head = p->next;
    p->next = NULL;
}
void insert(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}
void print(struct node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL");
}

int main(){
    struct node *head = NULL;
    int a,k;
    int arr[5];
    for (int i = 0; i <5; i++)
    {
         scanf("%d",&arr[i]);
        
    }
    for (int i = 1; i <=5; i++)
    {
         insert(&head,arr[5-i]);
        //   printf("%d",arr[5-i]);
    }
  
    scanf("%d",&k);
    rotate(&head, k-1);
    print(head);
    return 0;
}