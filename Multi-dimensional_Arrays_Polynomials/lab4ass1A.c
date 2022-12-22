#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

void create_node() // Function to create a node;
{
    int no;

    printf("Enter the number of nodes : ");
    scanf("%d", &no);

    struct node *a;
    int i;
    printf("Enter data : \n");
    for (i = 0; i < no; i++)
    {
        a = (struct node *)malloc(sizeof(struct node));
        printf("Data %d : ", i + 1);
        scanf("%d", &a->data);
        a->next = NULL;
        if (head == NULL)
        {
            head = tail = a;
        }
        else
        {
            tail->next = a;
            tail = a;
        }
    }
}

void display_node()
{
    int i;
    struct node *temp;
    temp = head;
    for (temp; temp != NULL; temp = temp->next)
    {
        printf("Data %d  | Address %u | Next address %u\n", temp->data, temp, temp->next);
    }
}

void insertAtFront()
{
    int info;
    struct node *n;
    n = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &info);
    n->data = info;
    n->next = head;
    head = n;
}

void insert_end() // okk
{
    int data1;
    struct node *temp, *h;
    temp = malloc(sizeof(struct node));

    // Enter the number
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data1);

    temp->next = 0;
    temp->data = data1;
    h = head;
    while (h->next != NULL)
    {
        h = h->next;
    }
    h->next = temp;
}

void insertat_k()
{
    struct node *temp, *nd;
    int p, d, i = 1;
    nd = malloc(sizeof(struct node));

    printf("\nEnter position and data :");
    scanf("%d %d", &p, &d);

    temp = head;
    nd->data = d;
    nd->next = NULL;
    while (i < p - 1)
    {
        temp = temp->next;
        i++;
    }
    nd->next = temp->next;
    temp->next = nd;
}

int main() // main function
{
    int ch;
    while (1)
    {

        printf("1 : To create a list.\n");
        printf("2 : To see the list.\n");
        printf("3 : To insert data at the begining.\n");
        printf("4 : To insert data at end.\n");
        printf("5 : To insert data at the k_th location.\n");


        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            create_node();
            break;
        }
        case 2:
        {
            display_node();
            break;
        }
        case 3:
        {
            insertAtFront();
            display_node();
            break;
        }
        

        case 4:
        {
            insert_end();
            break;
        }
        case 5:
        {
            insertat_k();
            break;
        }
        default:
        {
            printf("Incorrect choice.");
            exit(0);
        }
    }
    }
    return 0;
}