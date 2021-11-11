int decrypt (int r, int c, char message[], char result[])
{
    char **grid;
    int ans;
    int k=0;
    grid = calloc(r, sizeof(char*));
    for (int j=0; j<r;j+=1)
    {
        grid[j] = calloc(c,sizeof(char));
    }
    int length = strlen (message);
    if (length > r*c) //works, condition 1 is that the dimensiosn must make sense
    {
        ans =0;
        return ans;
    }

    else
    {
        for (int i=0; i<r; i+=1)
        {
            for (int j=0; j<c;j+=1)
            {
                if (message[k] == '@' && k== (length-1))
                {
                    grid[i][j] = '\0';
                }
                else if (message[k] =='@' && k!=(length-1))
                 {
                     return 0;
                 }
                else
                {
                    grid[i][j] = message[k];
                }
                k+=1;
            }
        }

        k=0;
        for (int j=0; j<c; j+=1)
        {
            for (int i=0; i<r; i+=1)
            {
                result[k] = grid[i][j];
                k+=1;
            }
        }
        result[k]= '\0';

    }
    printf ("\nDecrypted Message:%s", result);
}
int encrypt (int r, int c, char message[], char result[])
{
    char **grid;
    int ans;
    int k=0;
    grid = calloc(r, sizeof(char*));
    for (int j=0; j<r;j+=1)
    {
        grid[j] = calloc(c,sizeof(char));
    }
    int length = strlen (message);
    if (length > r*c) //works, condition 1 is that the dimensiosn must make sense
    {
        ans =0;
        return ans;
    }
    else
    {
        for (int i=0; i<r; i+=1)
        {
            for (int j=0; j<c;j+=1)
            {
                if (message[k] == '\0')
                {
                    grid[i][j] = '@';
                }
                else
                {
                    grid[i][j] = message[k];
                }
                k+=1;
            }
        }
        k=0;
        for (int j=0; j<c; j+=1)
        {
            for (int i=0; i<r; i+=1)
            {
                result[k] = grid[i][j];
                k+=1;
            }
        }
        result[k]= '\0';

    }
    printf ("\nEncrypted Message:%s", result);
}
