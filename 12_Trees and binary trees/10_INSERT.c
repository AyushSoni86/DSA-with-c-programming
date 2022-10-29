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
void InOrder(struct node * root){
    if (root!=NULL)
    {
        InOrder(root->left);
        printf(" %d ",root->data);
        InOrder(root->right);
    }
    
}

void Insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot Insert %d, Already exists in the tree\n", key);
            return;
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
    struct node *new = CreateNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = CreateNode(5);
    struct node *p1 = CreateNode(3);
    struct node *p2 = CreateNode(6);
    struct node *p3 = CreateNode(1);
    struct node *p4 = CreateNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    Insert(p, 2);
    // printf("%d", p->right->right->data);
    InOrder(p);
    return 0;
}
