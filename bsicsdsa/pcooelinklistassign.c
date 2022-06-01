#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    char arr[50];
    char name[50];
    struct node *next;
};
struct node *insert_at_end(struct node *head, int n)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct node *head = NULL;
    int a;
    printf("Enter the designation you want to add President('p'),Member('m'),Secretory('s')\n");
    sscanf("%d",&a);
    if(head==NULL){
        printf("pls head is empty ");
    }

    

    display(head);
    return 0;
}