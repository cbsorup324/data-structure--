#include<stdio.h>
int stack[100],choice,n,top,x,i;
void s_push();
void s_pop();
void display();

int main()
{
    top = -1;
    printf("Enter the size of stack :");
    scanf("%d",&n);
    printf("Press 1. push \n 2. pop\n 3. display \n 4. exit");
 

    while(choice != 4)
    {

    printf("Enter the choice \n");
    scanf("%d",choice);

        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Not a valid choice");
            }

    }

}
void s_push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void s_pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}