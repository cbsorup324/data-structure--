#include <stdio.h>

int search(int a[], int c, int x)
{
    for (int i = 0; i < c; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    int x;
    int a[30];
    printf("Enter the array size :");
    scanf("%d", &n);
    printf("Enter the array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be found :");
    scanf("%d", &x);

    int result = search(a, n, x);
    if (result == -1)
    {

        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }
    return 0;
}