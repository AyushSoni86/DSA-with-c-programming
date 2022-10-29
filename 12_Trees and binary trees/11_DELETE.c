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
struct node *InOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *delete (struct node *root, int key)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        ipre = InOrderPredecessor(root);
        root->data = ipre->data;
        root->left = delete (root->left, ipre->data);
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

    //        50
    //      /    \
    //    30     80
    //   /  \   /  \
    //  20  40 70  90

    p0->left = p1;
    p0->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;
    printf("\nPerforming InOrder traversal.........\n\n");
    InOrder(p0);
    printf("\nThe root node is %d\n",p0->data);
    printf("\n");
    delete(p0,50);
    InOrder(p0);
    printf("\nThe root node is %d\n",p0->data);
    
     //        50
     //      /    \
     //    30     80
     //   /  \   /  \
     //  20  40 70  90

    return 0;
}