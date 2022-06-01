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
int isBST(struct node *root)
{
      static struct node * prev =NULL;
    if (root != NULL){

        if (!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data){
            return 0;
        }
        prev =root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
   
}
int main()
{

    // constructing the root node -using the function
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

        //          5
        //        /   \
        //      3      6
        //    /   \
        // 1        4


    //linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inordertraversal(p);
    printf("\n");
    printf("%d",isBST(p));
    return 0;
}