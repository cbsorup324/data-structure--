#include<stdio.h>

int percentage();

float Var;
int count=1;
float p;

int main()
{

    printf("\n Enter a value to see it's percentage: ");
    scanf("%f",&Var);

    Var=Var/100;
    percentage();
    printf("\n");
    return 0;
}

int percentage()
{

    if(count==51)
    {
        return 1;
    }

    p=Var*count;
    printf("\n%3d Percent = %.02f",count, p);
    count++;
    percentage();
    return 0;
}