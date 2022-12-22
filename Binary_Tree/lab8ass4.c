#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} s;

s *createNode(int data)
{
    s *n;
    n = (s *)malloc(sizeof(s));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preorder(s *n)
{
    if (n != NULL)
    {
        if ((n->right == NULL && n->left != NULL) || (n->right != NULL && n->left == NULL))
        {
            printf("%d", n->data);
            preorder(n->left);
            preorder(n->right);
        }
    }
}
int main()
{
    s *p = createNode(4);
    s *p1 = createNode(1);
    s *p2 = createNode(6);
    s *p3 = createNode(5);
    s *p4 = createNode(2);
    s *p5 = createNode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;

    preorder(p);
    return 0;
}