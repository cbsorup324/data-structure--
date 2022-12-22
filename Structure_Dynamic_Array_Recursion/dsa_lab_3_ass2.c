#include <stdio.h>
#include <stdlib.h>
int main()
{
    int * ptr;
    int i, n, j, k, temp, c = 0;
    printf("Enter size of the  array : ");
    scanf("%d", &n);
 
    ptr = (int *)calloc(n, sizeof(int));
    int b[n];
    printf("Enter elements in array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        if (*(ptr + i) % 2 == 1)
            c++;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((ptr + j) > (ptr + j + 1))
            {
                temp = *(ptr + j);
                *(ptr + j) = (ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    k = 0;
    j = n - c;
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) % 2 == 0)
        {
            if (k < n - c)
                b[k++] = *(ptr + i);
        }
        else
        {
            if (j < n)
                b[j++] = *(ptr + i);
        }
    }
    printf("\n Array after sorting even and odd elements separately:\n ");
    for (i = 0; i < n; i++)
    {
        *(ptr + i) = b[i];
        printf("%d ", *(ptr + i));
    }
    return 0;
}