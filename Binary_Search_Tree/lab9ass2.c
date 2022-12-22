/*Write a menu driven program to perform following for a BST

o Create node
o Insert node in a BST.
o Delete node in a BST.
o Display function
o Inorder, pre-order, and post-order Traversal*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} s;

s *create(int item)
{
    s *temp = (s *)malloc(sizeof(s));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(s *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \t", root->key);
        inorder(root->right);
    }
}

void preorder(s *root)
{
    if (root != NULL)
    {
        printf("%d \t", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(s *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t", root->key);
    }
}
s *dlte(s *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = dlte(root->left, key);

    else if (key > root->key)
        root->right = dlte(root->right, key);

    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        
    }
    printf("\n The deleted node \n%d \t", root->key);
    return root;
}

s *insert(s *n, int key)
{
    if (n == NULL)
    {
        return create(key);
    }
    if (key < n->key)
        n->left = insert(n->left, key);
    else if (key > n->key)
        n->right = insert(n->right, key);
    return n;
}

int main()
{
    s *root = NULL;
    root = insert(root, 30);
    insert(root, 43);
    insert(root, 52);
    insert(root, 64);
    insert(root, 77);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    dlte(root, 43                                                                         );
    return 0;
}