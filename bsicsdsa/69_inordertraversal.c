#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *n;                                 // creating the node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating the memory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to null
    n->right = NULL;                                // setting the left and right children to null
    return n;                                       // finally returning the second node
}

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}
int main()
{
    
    // constructing the root node -using the function
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);

    //linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inordertraversal(p);
    return 0;
}