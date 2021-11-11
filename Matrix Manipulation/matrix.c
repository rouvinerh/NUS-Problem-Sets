#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

void prodMatrix (int rowsa, int columnsa, int rowsb, int columnsb, int a[][100], int b[][100])
{
int i,j,k;
int prod[100][100];
int temp;

for (i=0; i<rowsa;i+=1)
{
    for (j=0; j<columnsb; j+=1)
    {
        prod [i][j] = 0;

        for (k=0; k<rowsb;k+=1)
        {
            prod [i][j] += (a[i][k]* b[k][j]);

        }
        printf ("\n%d", prod[i][j]);
    }

}
}

void sumMatrix (int rows, int columns,int a[][100], int b[][100])
{
int sum[100][100];
int i, j;

for (j=0; j<rows; j+=1)
{
    for (i=0; i<columns;i+=1)
    {
        sum[j][i] = a[j][i]+ b[j][i];
        printf ("%d,", sum[j][i]);
    }
}

}

int main()
{
int a[100][100];
int b [100][100];
int i, j;

int rowsa, columnsa;
int rowsb, columnsb;
printf ("Matrix A:\n");
printf ("Enter number of rows and columns:");

scanf ("%d %d", &rowsa, &columnsa);
printf ("\nEnter values for matrix:");

for (j=0; j<rowsa; j+=1)
{
    for (i=0; i<columnsa; i+=1)
    {
        scanf ("%d", &a[j][i]);
    }
}
j=0;
i=0;
printf ("Matrix B:\n");
printf ("Enter number of rows and columns:");

scanf ("%d %d", &rowsb, &columnsb);
printf ("\nEnter values for matrix:");

for (j=0; j<rowsb; j+=1)
{
    for (i=0; i<columnsb; i+=1)
    {
        scanf ("%d", &b[j][i]);
    }
}

//sumMatrix (rowsa, columnsa, a,b);
prodMatrix (rowsa, columnsa, rowsb, columnsb, a,b);
return 0;
}
