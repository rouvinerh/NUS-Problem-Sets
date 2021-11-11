#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

void speedup (int array[], int length, int actualsize, int speed)
{
    int i;
    for (i=0; i<length;i+=speed)
    {
        printf ("%d ", array[i]);
    }
}

void slowdown (int array[], int length, int actualsize, int speed)
{
int speed1 = speed;
int i=0;
while (actualsize >0 && i<length)
    {
        while (speed <0)
        {
            printf ("%d ", array[i]);
            speed+=1;
        }
        actualsize +=speed1;
        speed = speed1;
        i+=1;
    }
}

int scan (int size, int speed)
{
    int actualsize;
    if (speed <0)
    {actualsize = size * (-speed);
    return actualsize;}

    else if (speed >0)
    {
        float speedf = speed;
        float multiplier = (1/speedf);
        actualsize = size * multiplier;
        return actualsize;
    }
}

int main()
{
    int size;
    int values[100];
    int speed;
    int actualsize;


    printf ("Enter size:");
    scanf ("%d", &size);
    printf ("\nEnter Values:");
    for (int i=0; i<size; i+=1)
    {
        scanf ("%d", &values[i]);
    }
    printf ("\nEnter speed:");
    scanf ("%d", &speed);
    printf ("\n");
    actualsize = scan (size, speed);
    if (speed < 0)
    {
        slowdown(values, size, actualsize, speed);
    }
    else if (speed >0)
    {
        speedup (values, size, actualsize, speed);
    }
  return 0;


}
