int main()
{
int matrix [10][10];
printf ("Enter size of array:");
int row, column;
scanf ("%d %d", &row, &column);
int i;
int j;
int diag;
int count;
printf ("Enter values:\n");
for (i=0; i<row;i+=1)
{
    for (j=0;j<column; j+=1)
    {
        scanf ("%d", &matrix[i][j]);
    }
}
i=0;
j=0;
do
{
    if (matrix[i][i] != 0)
    {
    diag=1;
    i+=1;
    }
    else if (matrix [i][i]=0)
    {
    diag=0;
    break;
    }
}while (i<row);
if (diag =1)
{
    printf ("Matrix is a diagonal matrix.");
    i=0;
}
else if (diag =0)
{
    printf ("Matrix is not a diagonal matrix.");
    i=0;
}


do
{
    if (matrix[i][j] != 0)
    {
        j+=1;
    }
    count +=1;
    j = count;
    i+=1;
    int square =1;

    if (matrix[i][j] = 0)
    {
        printf ("Matrix is not an upper triangular matrix.");
        square =0;
    }
}while (i<row && j<column);

if (square =1)
{
    printf ("Matrix is an upper triangular matrix.");
}


}
