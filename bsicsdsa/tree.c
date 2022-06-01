#include <stdio.h>

struct node {
    struct node * leftchild;
    struct node *rightchild;
    int data;
};
//  inorder traversal 
void traversal (struct node * root){
    traversal(root->leftchild);
    printf("%d",root->data);
    traversal(root->rightchild);
}

struct node * insert(struct node *root){
 struct 
}


int main(){

}