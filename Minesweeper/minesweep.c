int main() //lazy to use functions lol
{
    int level;
    char **mines;
    int **ans;
    int r;
    int c;
    printf ("Enter level:");
    scanf ("%d", &level);

    if (level ==1)
    {
         r=8;
         c=8;
    }
    else if (level ==2)
    {
         r=12;
         c=16;
    }
    else if (level ==3)
    {
         r=16;
         c=30;
    }
    else
    {
        printf ("\nInvalid level");
    }
    printf ("\nLevel Chosen: %d\n", level);

    mines = calloc(r, sizeof (int*));
    ans = calloc(r,sizeof(int*));

    for (int i=0; i<r; i+=1)
    {
        mines[i] = calloc(c, sizeof(int));
        ans[i] = calloc(c, sizeof(int));
    }

    for (int i=0; i<r;i+=1)
    {
        scanf ("%s[^\n]", mines[i]);
    }

    for (int i=0; i<r; i+=1)
    {
        for (int j=0; j<c;j+=1)
        {
            ans[i][j] =0;
        }
    }

    for (int i=1; i<r-1; i+=1) //checks all safe elements
    {
        for (int j=1; j<c-1;j+=1)
        {
            if (mines[i][j] == '*') //works!
            {
                ans[i][j] =9;
            }
            else if (mines[i][j] == '-')
            {

                char up = mines[i-1][j];
                char down = mines[i+1][j];
                char left = mines[i][j-1];
                char right= mines[i][j+1];
                char topleft = mines[i-1][j-1];
                char topright = mines[i-1][j+1];
                char bottomleft = mines[i+1][j-1];
                char bottomright= mines[i+1][j+1];

                if (up =='*')
                {
                    ans[i][j] +=1;
                }
                if (down =='*')
                {
                    ans[i][j] +=1;
                }
                if (left =='*')
                {
                    ans[i][j] +=1;
                }
                if (right =='*')
                {
                    ans[i][j] +=1;
                }
                if (topleft =='*')
                {
                    ans[i][j] +=1;
                }
                if (topright =='*')
                {
                    ans[i][j] +=1;
                }
                if (bottomleft =='*')
                {
                    ans[i][j] +=1;
                }
                if (bottomright =='*')
                {
                    ans[i][j] +=1;
                }
            }
        }

    }
    for (int i=0; i<r; i+=(r-1)) //checks first and last row, no corners;
    {
         for (int j=1; j<c-1; j+=1)
        {
            if (mines[i][j] == '*')
                {
                    ans[i][j] =9;
                }
            else if (mines[i][j] == '-' && i==0) //checks first row
                {
                    char down = mines[i+1][j];
                    char left = mines[i][j-1];
                    char right= mines[i][j+1];
                    char bottomleft = mines[i+1][j-1];
                    char bottomright= mines[i+1][j+1];

                    if (down =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (left =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (right =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (bottomleft =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (bottomright =='*')
                    {
                        ans[i][j] +=1;
                    }
                }
                else if (mines[i][j] == '-' && i==(r-1)) //checks last row
                {
                    char up = mines[i-1][j];
                    char left = mines[i][j-1];
                    char right= mines[i][j+1];
                    char topleft = mines[i-1][j-1];
                    char topright = mines[i-1][j+1];

                    if (up =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (left =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (right =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (topleft =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (topright =='*')
                    {
                        ans[i][j] +=1;
                    }
                }
        }
    }
    for (int i=0; i<r;i+=(r-1)) //checks corners
    {
        for (int j=0; j<c; j+=(c-1))
        {
            if (mines[i][j] == '*')
                {
                    ans[i][j] =9;
                }
            else if (mines[i][j] =='-')
            {
                if (i==0 && j==0) //top left
                {
                    char down = mines[i+1][j];
                    char right= mines[i][j+1];
                    char bottomright= mines[i+1][j+1];

                    if (down =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (right =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (bottomright =='*')
                    {
                        ans[i][j] +=1;
                    }
                }
                if (i==0 && j==(c-1))//topright
                {
                    char down = mines[i+1][j];
                    char left = mines[i][j-1];
                    char bottomleft = mines[i+1][j-1];

                    if (down =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (left =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (bottomleft =='*')
                    {
                        ans[i][j] +=1;
                    }
                }
                if (i==(r-1) && j==0)//bottom left
                {
                    char up = mines[i-1][j];
                    char right= mines[i][j+1];
                    char topright = mines[i-1][j+1];

                    if (up =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (right =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (topright =='*')
                    {
                        ans[i][j] +=1;
                    }

                }

                if (i==(r-1) && j==(c-1)) //bottom right
                {
                    char up = mines[i-1][j];
                    char left= mines[i][j-1];
                    char topleft = mines[i-1][j-1];

                    if (up =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (left =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (topleft =='*')
                    {
                        ans[i][j] +=1;
                    }
                }
            }
        }
    }
    for (int i=1; i<r-1; i+=1)
    {
        for (int j=0; j<c;j+=c-1)
        {
            if (mines[i][j] == '*')
                {
                    ans[i][j] =9;
                }
            else if (mines[i][j] == '-' && j==0) //checks first column
                {
                    char up = mines[i-1][j];
                    char down = mines[i+1][j];
                    char right= mines[i][j+1];
                    char topright = mines[i-1][j+1];
                    char bottomright= mines[i+1][j+1];

                    if (up =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (down =='*')
                    {
                        ans[i][j] +=1;
                    }
                    if (right =='*')
                    {
                        ans[i][j] +=1;
                    }

                    if (topright =='*')
                    {
                        ans[i][j] +=1;
                    }

                    if (bottomright =='*')
                    {
                        ans[i][j] +=1;
                    }
                }
            else if (mines[i][j] == '-' && j==(c-1))
            {
                char up = mines[i-1][j];
                char down = mines[i+1][j];
                char left = mines[i][j-1];
                char topleft = mines[i-1][j-1];

                char bottomleft = mines[i+1][j-1];


                if (up =='*')
                {
                    ans[i][j] +=1;
                }
                if (down =='*')
                {
                    ans[i][j] +=1;
                }
                if (left =='*')
                {
                    ans[i][j] +=1;
                }

                if (topleft =='*')
                {
                    ans[i][j] +=1;
                }

                if (bottomleft =='*')
                {
                    ans[i][j] +=1;
                }
            }
        }
    }
    for (int i=0; i<r; i+=1)
    {
        for (int j=0; j<c;j+=1)
        {
            printf ("%d ", ans[i][j]);
        }
        printf ("\n");
    }

}
