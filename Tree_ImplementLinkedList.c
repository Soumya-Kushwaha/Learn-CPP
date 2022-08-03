#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *createnode(char data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void preorder(struct node *root)
{
    if (root == NULL){
        return;
    }
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    
}
void postorder(struct node *root)
{
    if (root != NULL)
    {        
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
int main()
{

    struct node *p1 = createnode('A');
    struct node *p2 = createnode('B');
    struct node *p3 = createnode('C');
    struct node *p4 = createnode('D');
    struct node *p5 = createnode('E');

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    printf("\nSoumya's Data Structures Lab Assignment 7: \n");
    printf("\nPreorder Traversal: \n");
    preorder(p1);
    printf("\n\nPostorder Traversal: \n");
    postorder(p1);
    printf("\n\nInorder Traversal: \n");
    inorder(p1);
    return 0;
}