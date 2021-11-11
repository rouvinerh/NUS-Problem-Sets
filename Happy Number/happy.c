//im not sure if recursion is allowed to be used for this problem, but it was the easiest solution to me at the time
int compute (int i, int ans)
{

    if (ans == 1 || ans == 4 || ans== 16 || ans == 20 || ans == 37 || ans == 42 || ans == 58 || ans == 89 || ans == 145)
    {
        return ans;
    }
    ans =0;
    while (i != 0)
    {
        int temp;
        temp = i%10;
        ans += (temp * temp);
        i/=10;
    }
    if (i==0)
    {
       i=ans;
       compute (i, ans);
    }

}

int happy (int lower, int upper)
{
    int temp;
    int count;
    int num;
    int ans;
    for (int i=lower; i<=upper; i+=1)
    {
        num = compute(i, ans);
        if (num ==1)
        {
            count+=1;
        }
    }
    return count;

}

int main()
{
    int lower, upper;
    int ans1, ans2;
    printf ("Enter 1st range:");
    scanf ("%d %d", &lower, &upper);
    ans1 = happy (lower, upper);
    printf ("\nNumber of happy: %d", ans1);

}
