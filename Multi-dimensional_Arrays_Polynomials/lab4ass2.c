#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter matrics m X n :\n");
    scanf("%d %d", &a,&b);
    int mat[a][b];
    int flag = 0;
    printf("Enter matrics eliments:\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("\t%d", mat[i][j]);
            if (mat[i][j] == 0)
            {
                flag++;
            }
        }
        printf("\n");
    }

    if (flag > ((a * b) / 2))
    {
        printf("It is a sparse matrix\n");
    }
    else
    {
        printf("It is a not sparse matrix\n");
    }
    return 0;
}