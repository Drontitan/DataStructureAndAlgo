#include <stdio.h>
#include <stdlib.h>
struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversel(struct node *ptr)
{
     printf("printing the elements of the linked the list \n");
    while (ptr != NULL)
    {
        printf("element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    struct node *n= (struct node *) malloc(sizeof(struct node ));
    if(n==NULL){
        printf("queue is full");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;

        }
        else{
            r->next=n;
            r=n;
        }
    }
}
int dequeue()
{   
    int val =-1;
    struct node *ptr =f;
    if(f==NULL){
        printf("queue is empty\n");
    }
    else{
       f=f->next;
       val=ptr->data;
       free(ptr);
    }
    return val;
}
int main(){
 
    linkedlisttraversel(f);
    printf("dequeing the element %d\n",dequeue());
    enqueue(34);
    enqueue(67);
    enqueue(89);
    printf("dequeing the element %d\n",dequeue()); 
    linkedlisttraversel(f);
    return 0;      
}