#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void heapify(int *a, int n, int i)
{
    int lg = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    if (l < n && a[l] > a[lg])
        lg = l;
 
    if (r < n && a[r] > a[lg])
        lg = r;
 
    if (lg != i)
    {
        swap(&a[i], &a[lg]);
 
        heapify(a, n, lg);
    }
}
 
void heapSort(int *a, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
 
    for (i=n-1; i>=0; i--)
    {
        swap(&a[0], &a[i]);
 
        heapify(a, i, 0);
    }
}
 
void printArray(int a[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
 
int main()
{
    int a[] = {15, 13, 11, 10, 16, 12};
    int n = sizeof(a)/sizeof(a[0]);
 
    heapSort(a, n);
 
    printf("Sorted array is \n");
    printArray(a, n);
    return 0;
}