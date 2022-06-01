#include <bits/stdc++.h>
// always ues the fast and slow pointers if we are in the cycle 
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node * middlenodeofhead(struct node * node){
    struct node * slow=node;
    struct node * fast=node;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
struct node * reverselist(struct node * head){  
       struct node *pre = NULL;
       struct node *next = NULL;
       struct node * temp=head;
       while (temp!=NULL)
       {
          next=temp->next;
          temp->next=pre;
          pre=temp;
          temp=next;
       }
       head=pre;
      return head;
}

bool ispalindrome( struct node * node){
     struct node * ptr =middlenodeofhead(node);
     struct node *headsecond = reverselist(ptr);
     struct node * temp = headsecond;
     while(node!=NULL && headsecond !=NULL){
           if(node->data!=headsecond->data){
               break;
           }
           node=node->next;
           headsecond=headsecond->next;
     }
    if(node== NULL && headsecond ==NULL){
          return true;
    }
    return false;

}
void linkedlisttraversel(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d \n", ptr->data);
        ptr = ptr->next;
    }
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
        third->data=2;
        third->next=fourth;
        fourth->data=1;
        fourth->next=NULL;
        cout<<ispalindrome(head);
        return 0;
    }