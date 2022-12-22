#include <stdio.h>

int binarys(int a[], int fst, int lst, int x)
{
    if (lst >= fst)
    {
        int mid = fst + (lst - fst) / 2;

        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] > x)
        {
            return binarys(a, fst, mid - 1, x);
        }
        if (a[mid] < x)
        {
            return binarys(a, mid + 1, lst, x);
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

    int result = binarys(a, 0, n - 1, x);

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