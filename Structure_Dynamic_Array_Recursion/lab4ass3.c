#include<stdio.h>

void sprax(term a[],term b[])
{
    int rowterms[MAX_COL],startpos[MAX_COL];
    int i,j,numcol = a[0].col,numterms = a[0];
    b[0].row = numcol;
    b[0].col =  a[0].row;
    b[0] .value = numterms;
    if (numterms > 0){
        for(i=0; i<numcol;i++){
            rowterms[i] = 0;
        }
        for(i=1; i<numterms; i++)
        {
            rowterms[a[i].col]++;
        }
        startpos[0]=1;
        for(i=1; i < numcol;i++)
        {
            startpos[i] = startpos[i-1] + rowterms[i -1];
        }
        for(i=1; i <= numterms; i++)
        {
            j = startpos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main()
{

}