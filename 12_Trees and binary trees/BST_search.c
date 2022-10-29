#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
     return n;
}

void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf(" %d ", root->data);
        InOrder(root->right);
    }
    
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    { 
        return search(root->right, key);
    }
}
int main()
{
    struct node *p0 = CreateNode(50);
    struct node *p1 = CreateNode(30);
    struct node *p2 = CreateNode(80);
    struct node *p3 = CreateNode(20);
    struct node *p4 = CreateNode(40);
    struct node *p5 = CreateNode(70);
    struct node *p6 = CreateNode(90);
    // struct node *p0=CreateNode(50);

    p0->left = p1;
    p0->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;
    printf("\nPerforming InOrder traversal.........\n\n");
    InOrder(p0);

    struct node *n=search(p0,300);
    if (n!=NULL)
    {
       printf("\nCongrulation :) \n Element found - %d \n",n->data);
    }
    else
        printf("\nElement not found :( \n");
    return 0;
}