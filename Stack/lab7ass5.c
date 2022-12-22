//5
#include <math.h>
#include <stdio.h>

void insertionsort(int a[], int n)
{                         //if said i =1 menas 2nd element not 1 st one ,never print 
    int i,j,key;          // the first value,
    for(i=1; i<n; i++)   //will check from position 1 not 0
    {
        key = a[i];  //2nd st value is on key
        j = i-1;  // j is on position 1 means 1st value 
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;//as loop is running so j will decremented and wil be on previous pos
        }
        a[j+1]=key;  //now again j +1 will take the prevois pos;
    }
}
 
void main()
{
    int a[50],n;
    int i;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    printf("\nEnter elements of an array:\n");

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    insertionsort(a,n);

    printf("\n\nAfter sorting:\n");
    for(i=0; i<n; i++)
    {
        printf("\n%d", a[i]);
    }
}