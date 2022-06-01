#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
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
void push(struct stack *ptr, char val)
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
char  pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack overflow cannot pop  to stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
char paranthesismatch(char *exp) {
    // create and initialise the stack
    struct stack *sp;
    sp->size=100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
           push(sp,'(');
        }  
        else if (exp[i] == ')'){
            if(isempty(sp)){
                return 0;
            }
            pop(sp);
        } 
    }
    if(isempty(sp)){
        return 1;
    }
    else{
        return 0;
    }

    
}
//
int main()
{
      char* exp  ="(8*9*6(*8";
    if (paranthesismatch(exp))
    {
        printf("this paranthesis is matching");
    }
    else
    {
        printf("the  paranthesis is not matching ");
    }
    return 0;
}