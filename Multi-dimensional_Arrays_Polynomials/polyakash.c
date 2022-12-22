#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int coeff;
    int pow;
    struct link *next;
} poly;

void create_poly(poly **);
void show_poly(poly *);
void add_poly(poly **, poly *, poly *);

int main()
{
    int c;
    do
    {
        poly *poly1, *poly2, *poly3;

        printf("Create 1st expression:\n");
        create_poly(&poly1);
        printf("Stored the 1st expression:\n");
        show_poly(poly1);

        printf("Create 2nd expression:\n");
        create_poly(&poly2);
        printf("Stored the 2nd expression:\n");
        show_poly(poly2);

        add_poly(&poly3, poly1, poly2);
        show_poly(poly3);

        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &c);
    } while (c);
    return 0;
}
void create_poly(poly **node)
{
    int flag;
    int coeff, pow;
    poly *tmp_node;
    tmp_node = (poly *)malloc(sizeof(poly));
    *node = tmp_node;
    do
    {
        printf("Enter Coeff:\n");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("Enter Pow:\n");
        scanf("%d", &pow);
        tmp_node->pow = pow;

        tmp_node->next = NULL;

        printf("Continue adding more terms to the polynomial list?(Y = 1/N = 0):");
        scanf("%d", &flag);

        if (flag)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
void add_poly(poly **result, poly *p1, poly *p2)
{
    poly *tmp_node;
    tmp_node = (poly *)malloc(sizeof(poly));
    tmp_node->next = NULL;
    *result = tmp_node;
    while (p1 && p2)
    {
        if (p1->pow > p2->pow)
        {
            tmp_node->pow = p1->pow;
            tmp_node->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow)
        {
            tmp_node->pow = p2->pow;
            tmp_node->coeff = p2->coeff;
            p2 = p2->next;
        }
        else
        {
            tmp_node->pow = p1->pow;
            tmp_node->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 && p2)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
    while (p1 || p2)
    {
        tmp_node->next = (poly *)malloc(sizeof(poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;

        if (p1)
        {
            tmp_node->pow = p1->pow;
            tmp_node->coeff = p1->coeff;
            p1 = p1->next;
        }
        if (p2)
        {
            tmp_node->pow = p2->pow;
            tmp_node->coeff = p2->coeff;
            p2 = p2->next;
        }
    }
}
void show_poly(poly * node) {
    printf("The polynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}