#include <stdio.h>
int selection_sort();
float a[30];
int n;
int main()
{
    int i;
    printf("\nEnter size of an array: ");
    scanf("%d", &n);

    printf("\nEnter elements of an array:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }
    selection_sort();

    printf("\n\nAfter sorting:\n");

    for (i = 0; i < n; i++)
    {
        printf("\n%f", a[i]);
    }
    return 0;
}
int selection_sort()
{
    int i, j, m, t;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
                m = j;
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
    return 0;
}