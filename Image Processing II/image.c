void print(int **arr, int size)
{
    printf ("The image after flipping:\n");
    for (int i=0; i<size; i+=1)
    {
        for (int j=0; j<size; j+=1)
        {
            printf ("%d ", arr[i][j]);
        }
        printf ("\n");
    }
}

void rotate (int **arr, int size, int angle)
{
    int temp;
    if (angle == 90)
    {
        for (int i=0; i<size; i+=1)
        {
            for (int j=0; j<i+1;j+=1)
            {
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        temp=0;
        for (int i=0; i<size; i+=1)
        {
            for(int j=0; j<size/2; j+=1)
        {
            temp = arr[i][j];
            arr[i][j] = arr[i][size-1-j];
            arr[i][size-1-j] = temp;
        }
        }

    print (arr, size);
    }
    if (angle == 180)
    {
        for (int i=0; i<size/2; i+=1)
        {
            for(int j=0; j<size; j+=1)
            {
                temp = arr[i][j];
                arr[i][j] = arr[size-1-i][j];
                arr[size-1-i][j] = temp;
            }
        }
        temp =0;
        for (int i=0; i<size; i+=1)
        {
            for (int j=0; j<size/2 ; j+=1)
            {
                temp = arr[i][j];
                arr[i][j] = arr[i][size-1-j];
                arr[i][size-1-j] = temp;
            }
        }
    print (arr, size);
    }
    if (angle == 270)
    {

        for (int j=0; j<size; j+=1)
        {
            for (int i=0; i<j; i+=1)
            {
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        for (int i=0; i<size/2; i+=1)
        {
            for(int j=0; j<size; j+=1)
            {
                temp = arr[i][j];
                arr[i][j] = arr[size-1-i][j];
                arr[size-1-i][j] = temp;
            }
        }


    }
    print (arr, size);
    if (angle == 360 || angle == 0)
    {
        print (arr, size);
    }

}


int main()
{
    int size;
    int **arr;
    int angle;
    printf ("Enter size:");
    scanf ("%d", &size);
    printf ("Enter values:\n");

    arr = calloc(size, sizeof(int*));

    for (int i=0; i<size; i+=1)
    {
        arr[i] = calloc(size, sizeof(int));
    }
    for (int i=0; i<size; i+=1)
    {
        for (int j=0; j<size;j+=1)
        {
            arr[i][j] = 0;
        }
    }
    for (int i=0; i<size; i+=1)
    {
        for (int j=0; j<size;j+=1)
        {
            scanf ("%d", &arr[i][j]);
        }
    }
    printf ("passed array:\n");
    for (int i=0; i<size; i+=1)
    {
        for (int j=0; j<size;j+=1)
        {printf ("%d ", arr[i][j]);
        }
        printf ("\n");
    }

    printf ("\nEnter angle of rotation:");
    scanf ("%d", &angle);

    rotate (arr, size, angle);

    for (int i=0; i<size; i+=1)
    { free(arr[i]);}
    free (arr);

return 0;
}
