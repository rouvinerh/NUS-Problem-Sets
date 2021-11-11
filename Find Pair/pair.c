int findPair (int array[], int number, int sum, int *n1, int *n2)
{
    *n1 =0;
    *n2 =0;
    int temp;
    for (int i =0; i<number; i+=1)
    {
        for (int j =0; j<number; j+=1)
        {
            temp = array[i] + array[j];
            if (temp!=sum)
            {
                temp =0;
            }
            else if (temp = sum)
            {
                *n1 = array[i];
                *n2 = array[j];
                return 1;
            }
        }
    }
    return 0;
}


int main(){

int number;
int array[10];
int sum;
int ans;

int n1, n2;

printf ("Enter number of elements.");
scanf ("%d", &number);
printf ("\nEnter %d integers:", number);
for (int i=0; i<number; i+=1)
{
    scanf ("%d", &array[i]);
}
printf ("\nEnter target sum: ");
scanf ("%d", &sum);

ans = findPair (array, number,sum, &n1, &n2);

if (ans ==1)
{
    printf ("The pair of values are %d and %d", n1, n2);
}
else if (ans ==0)
{
    printf ("No solution!");
}
}
