#include <stdio.h>
#include <stdlib.h>
struct stack{
   
   int data;
   struct stack *next;

};
void linkedlistraversal(struct stack *p){
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int  isfull(struct stack *top){
    struct stack *p=(struct stack *)malloc(sizeof(struct stack));
    if(p==NULL){
        return 1;
    }
   else{
       return 0;
   }
}
int isempty(struct stack * p){
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct stack* push(struct stack *top,int val){
    if(isfull(top)){
        printf("full\n");
    }
    else{
        struct stack *n=(struct stack *)malloc(sizeof(struct stack));
        n->data=val;
        n->next=top;
        top=n;
        return top;
    }
}
int pop (struct stack* *top){
    if(isempty(*top)){
       printf("stack underflow\n");
    }
    else{
       struct stack *ptr=*top;
        *top=(*top)->next;
        int a= ptr->data;
        free(ptr);
        return a;
    }
}
int main(){

    struct stack * top=NULL;
    top = push(top, 78);
    top = push(top, 72);
    top = push(top, 45);
    linkedlistraversal(top);
    int element =pop(&top);
    printf("pop : %d from the stack\n", element);
    linkedlistraversal(top);
}