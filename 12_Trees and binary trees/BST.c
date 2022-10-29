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

int IsBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!IsBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return IsBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node *p0 = CreateNode(9);
    struct node *p1 = CreateNode(4);
    struct node *p2 = CreateNode(11);
    struct node *p3 = CreateNode(2);
    struct node *p4 = CreateNode(7);
    struct node *p5 = CreateNode(15);
    struct node *p6 = CreateNode(5);
    struct node *p7 = CreateNode(8);
    struct node *p8 = CreateNode(14);

    p0->left = p1;
    p0->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p2->right = p5;

    p4->left = p6;
    p4->right = p7;

    p5->left = p8;
    p5->right = NULL;

    printf("Performing InOrder traversal...........\n");
    InOrder(p0);
    printf("\n");
    if (IsBST(p0))
        printf("The given tree is a Binary search tree\n");
    else
        printf("The given tree is Not a Binary search tree\n");

    return 0;
}