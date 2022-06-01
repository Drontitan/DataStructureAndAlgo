#include <bits/stdc++.h>
// always ues the fast and slow pointers if we are in the cycle 

struct node
{
    int data;
    struct node *next;
};


// // using the recursion 
// struct node *reverserthelinkedlist(struct node * head,struct node * ptr){  
//         struct node * node =head;
//       if(node==ptr){
//           head=ptr;
//           return;
//       }
//        reverserthelinkedlist(node->next,ptr);
//         ptr->next=node;
//         ptr=node;
//         ptr->next=NULL;
//         return head;
//   }

// inpace reversal of the linkelist
struct node * reverser(struct node * head){  
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
        third->data=6;
        third->next=fourth;
        fourth->data=8;
        fourth->next=NULL;
        head=reverser(head);
        linkedlisttraversel(head);
        return 0;
    }