void maxPathValueUp (int *arr[10], int size)
{
    int max;
    int sum;
    for (int i =size-1; i>=0; i-=1)
    {
        for (int j=0; j<=size;j+=1)
        {
          if (arr[i][j] > arr[i][j+1])
          {
              arr[i-1][j] = arr[i-1][j] + arr[i][j];
          }
          else
          {
              arr[i-1][j] = arr[i-1][j] + arr[i][j+1];
          }
        }

    }
    max = arr[0][0];

    for (int j =0; j<size; j+=1)
    {
        if (arr[0][j] > max)
            max = arr[0][j];
    }

    printf ("The maximum path value from bottom to top is = %d", max);

}

void maxPathValueDown (int *arr[10], int size)
{
    int max;

    if (size>1)
    {
    arr[1][0] = arr[1][0] + arr[0][0];
    arr[1][1]= arr[1][1] + arr[0][0];
    }

    for (int i=2; i<size; i+=1)
    {
        arr[i][0] = arr[i][0] + arr[i-1][0];
        arr[i][i] = arr[i][i] + arr[i-1][i-1];

        for (int j=1 ; j<i ; j+=1)
        {
            if (arr[i][j] + arr[i-1][j] >= arr[i][j] + arr[i-1][j-1])
            {
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
            else
            {
                arr[i][j] = arr[i][j] + arr[i-1][j-1];
            }

        }

    }
    printf ("The final array is:\n\n");
    for (int r=0; r<size; r+=1)
    {
        for(int c=0; c<size; c+=1)
        {
            printf ("%d ", arr[r][c]);
        }
        printf ("\n");
    }
    max = arr[size-1][0];

    for (int k=1; k<size; k+=1)
    {
        if (arr[(size-1)][k]>max)
            {
                max = arr[(size-1)][k];
            }
    }
    printf ("\nMaximum path value from top to bottom = %d", max);

}
int main()
{
    int size;
    int *arr[10];
    int sum;
    int max;

    printf ("Enter number of rows:");
    scanf ("%d", &size);
    printf ("Enter values of the array:");

    for (int z=0; z<size;z+=1)
    {
        arr[z] = calloc(z+1, sizeof(int));
    }

    for (int r=0; r<size; r+=1)
    {
        for (int c=0; c<=r; c+=1)
        {
            scanf ("%d", &arr[r][c]);
        }
    }
    printf ("\n");
    for (int r=0; r<size; r+=1)
    {
        for (int c=0; c<=r; c+=1)
        {
            printf ("%d ", arr[r][c]);
        }
        printf ("\n");
    }

    maxPathValueUp(arr,size); 
    maxPathValueDown(arr.size);
