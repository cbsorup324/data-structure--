#include <stdio.h>
#include <stdlib.h>
void main()
{
    int c;
    do
    {
        printf("\n 1. Un-Directed Graph ");
        printf("\n 2. Exit ");
        printf("\n\n Select a proper c : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            undir_graph();
            break;
        case 2:
            exit(0);
        }
    } while (1);
}

int undir_graph()
{
    int a[50][50];
    int deg, i, j, n;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    read_graph(a, n);
    printf("\n Vertex \t Degree ");
    for (i = 1; i <= n; i++)
    {
        deg = 0;
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1)
                deg++;
        printf("\n %5d \t\t %d\n\n", i, deg);
    }
    return;
}

int read_graph(int a[50][50], int n)
{
    int i, j;
    char reply;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
                continue;
            }
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
            scanf("%c", &reply);
            if (reply == 'y' || reply == 'Y')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    return;
}