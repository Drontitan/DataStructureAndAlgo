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
struct node* wherethecylceisstarting(struct node *node){
    int count=0;
    struct node *fast =node;
     struct node *slow=node;
     int count=0;
     while(fast!=NULL && fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
         struct node *temp=slow;
       if(fast==slow){
          count=lenghtofcycle(slow);
          break;
       }
    }   
     if(count==0){
         return NULL;
     }

    // find the start node 
    struct node * f =node;
    struct node * s =node;
    while(count>0){
        f=f->next;
        count--;
    }
    while(f!=s){
      f=f->next;
      s=s->next;
    }
     return s;


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