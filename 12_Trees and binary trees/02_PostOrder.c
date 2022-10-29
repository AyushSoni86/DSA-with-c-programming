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

void PostOrder(struct node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf(" %d ", root->data);
    }
}
int main()
{
    struct node *p = CreateNode(2);
    struct node *p1 = CreateNode(6);
    struct node *p2 = CreateNode(3);
    struct node *p3 = CreateNode(9);
    struct node *p4 = CreateNode(8);
    struct node *p5 = CreateNode(5);
    struct node *p6 = CreateNode(22);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    PostOrder(p);

    return 0;
}