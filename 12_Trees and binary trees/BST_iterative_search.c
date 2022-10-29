#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
     return n;
}
struct node *IterSearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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
    // printf("\nPerforming InOrder traversal.........\n\n");
    // InOrder(p0);

    struct node *n = IterSearch(p0, 30);
    if (n != NULL)
    {
        printf("\nCongrulation :) \n Element found - %d \n", n->data);
    }
    else
        printf("\nElement not found :( \n");
    return 0;
}