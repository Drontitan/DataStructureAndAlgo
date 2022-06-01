#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void linkedlisttraversel(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *top, int a)
{
    if (isfull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = a;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct node *tp)
{
    if (isempty(tp))
    {
        printf("stack underflow\n");
    }
    else
    {
        struct node *n = tp;
        top =tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{

    top = push(top, 78);
    top = push(top, 72);
    top = push(top, 45);
    linkedlisttraversel(top);
    int element = pop(top);
    printf("poped element is : %d\n", element);
    linkedlisttraversel(top);
    return 0;
}