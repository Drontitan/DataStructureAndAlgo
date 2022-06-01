#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("stack overflow cannot push %d to stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack overflow cannot pop  to stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *sp,int i){
    int arrind = sp->top - i + 1;
     if (arrind < 0)
    {
        printf("not a valid position fot the stack\n ");
    }
    else{
        return sp->arr[arrind];
    }
}
 int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created sucessfully\n");

    printf("%d\n", isfull(sp));
    printf("%d\n", isempty(sp));

    push(sp, 58);
    push(sp, 54);
    push(sp, 58);
    push(sp, 56);
    push(sp, 78);
    push(sp, 90);
    push(sp, 34);
    push(sp, 23);
    push(sp, 45);
    push(sp, 48); //push 10 value
    // push(sp, 78); // stack overfow since the size of stack is full that is 10

    printf("after pushing %d\n", isfull(sp));
    printf("after pushing %d\n", isempty(sp));

    printf("pop %d from the stack\n", pop(sp)); //-- ;last in 1st out

    for (int  j = 1; j <= sp->top+1; j++)
    {
        printf("the value at position %d is %d\n", j, peek(sp,j));
    }
    return 0;
}