#include <stdio.h>
#include <stdlib.h>

//creating a binary tree in c language
//recommended to use this method

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
int main()
{
    struct node *p = CreateNode(6);
    struct node *p1 = CreateNode(7);
    struct node *p2 = CreateNode(70);
    struct node *p3 = CreateNode(91);
    struct node *p4 = CreateNode(21);
    struct node *p5 = CreateNode(26);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p2->right = p5;

  

  
    return 0;
}