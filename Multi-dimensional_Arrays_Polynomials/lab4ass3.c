#include <stdio.h>

int main()
{
    int m,n;
    n=3;
    printf("Enter matrix n X 3 :\n");
    scanf("%d",&m);
    int a1[m][n];
    int a2[m][n];


    printf("Enter matrx eliments:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a1[i][j]);
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            
           if (j==0)
           {
            a2[i][j]=a1[i][1];
           }
            else if (j==1)
           {
            a2[i][j]=a1[i][0];
           }
           else
           {
               a2[i][j]=a1[i][j];
           }
           
        }
         
    }
    
    int x,y,z;
    for(int i=1;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
         if(a2[i][0]>a2[j][0])
         {
             x=a2[i][0];
             y=a2[i][1];
             z=a2[i][2];
             a2[i][0]=a2[j][0];
             a2[i][1]=a2[j][1];
             a2[i][2]=a2[j][2];
             a2[j][0]=x;
             a2[j][1]=y;
             a2[j][2]=z;
         }
        }
    }
    

     
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           printf("\t%d",a2[i][j]);
          
        }
         printf("\n");
    }
    
    return 0;
}