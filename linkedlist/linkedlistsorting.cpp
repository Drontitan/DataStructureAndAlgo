#include <bits/stdc++.h>
// always ues the fast and slow pointers if we are in the cycle 

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

 bool hascycle(struct node *node){
     struct node *fast =node;
     struct node *slow=node;
     while(fast!=NULL && fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
       if(fast==slow){
           return true;
       }
    }   
    return false;
}


int  lenghtofcycle( struct node * node){
    struct node *fast =node;
     struct node *slow=node;
     int count=0;
     while(fast!=NULL && fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
         struct node *temp=slow;
       if(fast==slow){
           do
           {
               temp=temp->next;
               count++;
           } while (temp!=slow);
         return count;
       }
    }   
}

     int findsdquare(int n){
         int ans=0;
         while(n>0){
               int rem =n%10;
               ans+=rem*rem;
               n/=10;
         }
         return ans;
     }

 bool ishappynumber(int n){
    int slow=n;
    int fast=n;
    do
    {
       slow=findsdquare(slow);
       fast=findsdquare(findsdquare(fast));
    } while (slow!=fast);
    if(slow==1){
        return true;
    }
    return false;
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
        head->data=1;
        head->next=second;
        second->data=2;
        second->next=third;
        third->data=45;
        third->next=fourth;
        fourth->data=50;
        fourth->next=head;
        hascycle(head);

        return 0;
    }