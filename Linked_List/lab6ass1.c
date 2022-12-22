//1
#include<stdio.h>
#include <stdlib.h>


void main()
{
  int arr[100],top=-1,i,j,n,k,ch;

  printf("\nEnter the number of elements:");
  scanf("%d",&n);
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
    top++;
  }
  do
  {
    printf("\nStack operations using 1-D array:");
    printf("\n1.Check if the stack is empty.");
    printf("\n2.Display the contents of the stack.");
    printf("\n3.Push.");
    printf("\n4.Pop.");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      if(top==-1)
      {
        printf("\nStack is empty.");
      }
      else
      {
        printf("\nStack is not empty.");
      }
      break;
      case 2:
      printf("\nContents of the stack:");
      for(j=0;j<=top;j++)
      {
        printf("%d ",arr[j]);
      }
      break;
      case 3:
      printf("\nEnter element to push:");
      scanf("%d",&k);
      top++;
      arr[top]=k;
      break;
      case 4:
      if(top==-1)
      {
        printf("\nStack is empty.");
      }
      else
      {
        printf("\nPopped element is %d",arr[top]);
        top--;
      }
      break;

      default:
      printf("\nInvalid choice.");
      exit(0);
    }
  }while(ch!=5);

}