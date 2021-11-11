int ne(int r, int c)
{
    int count;

    if (r==0 || c==0)
    {
        return 1;
    }
    else
    {
        count = (ne(r-1, c)) + (ne(r,c-1));
    }
}

int main()
{
    int r, c;
    int count;
    printf ("Enter rows and columns apart:");
    scanf ("%d %d", &r, &c);
    count = ne(r,c);
    printf ("\nNumber of paths = %d", count);
}
