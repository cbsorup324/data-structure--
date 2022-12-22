#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr;
    int i, l;
    int flag = 0;
    printf(" Enter the leangth of the string :");
    scanf("%d", &l);
    ptr = (char *)malloc(l * sizeof(char));

    printf("Enter a string:");
    scanf("%s", ptr);

    for (i = 0; i < l; i++)
    {
        if (ptr[i] != ptr[l - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("%s is not palindrome", ptr);
    }
    else
    {
        printf("%s is palindrome", ptr);
    }
    return 0;
}