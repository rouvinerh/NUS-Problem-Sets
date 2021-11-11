void printMagic (int arr[][15], int size)
{
    int row, col;
    for (row=0; row<size; row+=1)
    {
        for(col=0;col<size;col+=1)
        {
            printf ("%d ", arr[row][col]);
        }
        printf ("\n");
    }
}
void generateMagic (int arr[][15], int size)
{
int last = size-1;
int row;
int col;
int temp;
int num;
for (row=0; row<size; row+=1)
{
    for(col=0; col<size; col+=1)
    {
        arr[row][col] =0;
    }
}
row = 0;
col = size/2;
arr[row][col] = 1;
for (num=2; num <= size*size;num+=1)
{
    row -=1;
    col +=1;
    if (row<0 && col>last)
    {
        if (arr[row][col] != 0)
        {
        row+=2;
        col-=1;
        }
        else
        {
        row = temp;
        row = col;
        col = temp;
        }


    }
    else if (row <0)
    {
        row = last;
    }
    else if (col>last)
    {
        col=0;
    }

    if (arr[row][col] != 0)
    {
       row +=2;
       col-=1;

    }
    arr[row][col] = num;


    }

printMagic (arr,size);
}

int main()
{
int size;
int arr[15][15];
printf ("Enter size:\n");
scanf ("%d", &size);

generateMagic(arr, size);

}
