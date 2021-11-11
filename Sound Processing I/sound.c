#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

void print(int array[], int size)
{
    int i;
    for (i=0; i<size; i+=1)
    {
        printf ("%d ", array[i]);
    }
}

int scan (int size, int echoes)
{
    int actualsize;
    actualsize = size * (echoes+1);
    return actualsize;
}

void echo (int values[], int size, int actualsize, float decay)
{
    float percentage;
    percentage = (100-decay) /100;

    print (values, size);
    actualsize -=4;
while (actualsize >0)
{
    int i;
    for (i=0; i<size; i+=1)
    {
        values[i] *= percentage;
    }
    print (values, size);
    actualsize -=4;
}
}


int main()
{
    int size, actualsize;
    int values[100];
    float decay;
    int echoes;
    printf ("Enter size:");
    scanf ("%d", &size);
    printf ("\nEnter Values");
    for (int i=0; i<size; i +=1)
    {
        scanf ("%d", &values[i]);
    }
    printf ("\nEnter number of echoes and decay percentage:");
    scanf ("%d %f", &echoes, &decay);
    printf ("\n");
    actualsize = scan (size, echoes);
    echo(values, size, actualsize, decay);
    return 0;
}
