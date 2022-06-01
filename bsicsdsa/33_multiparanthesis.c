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
char pop(struct stack *ptr)
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
char stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}
int match(char a,char b){
    if(a=='{'&& b=='}'){
        return 1;
    }
    if(a=='('&& b==')'){
        return 1;
    }
    if(a=='['&& b==']'){
        return 1;
    }
    else{
        return 0;
    }
    
}
char paranthesismatch(char *exp)
{
    // create and initialise the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char pop_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i]=='{' || exp[i]=='[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isempty(sp))
            {
                return 0;
            }
             pop_ch=pop(sp);
             if (!match( pop_ch,exp[i]))
             {
                 return 0;
             }
        }
    }
    if (isempty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//
int main()
{
    char *exp = "{[(8){[{*(9**)}]}]}";
    if (paranthesismatch(exp))
    {
        printf("this paranthesis are matching");
    }
    else
    {
        printf("the  paranthesis are not matching ");
    }
    return 0;
}