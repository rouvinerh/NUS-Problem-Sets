int present_thru_days(int days, int n)
{
    int giftday=0;
    int gifttotal=0;

    if (days == 1)
    {
        giftday +=1;
        gifttotal += giftday;

        return gifttotal;
    }
    else
    {
        for (int i=days; i>0; i-=1)
        {
            giftday += i;
        }
        if (days ==n )
        {
          printf ("\The number of presents received on day %d is %d", n,giftday);
        }
        gifttotal = giftday + present_thru_days (days-1,n);
    }
}

int main()
{
    int days;
    int total;
    int n;
    printf ("Enter number of days:");
    scanf ("%d", &days);
    n= days;
    total = present_thru_days(days, n);
    printf ("\nThe number of presents received in %d days is %d", days, total);
