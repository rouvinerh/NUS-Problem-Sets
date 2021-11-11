#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int isValidPassword (char domain[], char id[], char old[], char newer[], char confirm[])
{
    char dom1[] ="NUSSTF";
    char dom2[] = "NUSSTU";
    int flag1=0;
    int flag2=0;

    if (strcmp (domain,dom1) != 0 &&strcmp(domain, dom2)!=0)
    {
        printf ("\nDomain Error!");
        return -1;
    }

    if (strlen(newer) < 8)
    {
        printf ("\nToo Short!");
        return -1;
    }

    for (int i=0; newer[i] != '\0'; i+=1)
    {
        if (isalpha(newer[i]) == 0 && isdigit (newer[i]) == 0 && newer[i] != '_')
        {
            printf ("Invalid characters");
            return -1;
        }
        if (isalpha(newer[i])!= 0) //if char is letter
        {
            if (newer[i] >= 'A' && newer[i]<= 'Z' ) //contains any form of capital letters
            {
            flag1 = 1;
            }
        if (newer[i] >='a' && newer[i] <='z')
            {
            flag2=1;
            }
        }

    }

    if (flag1 ==0 || flag2 ==0)
    {
        printf ("\nPlease have both caps and smalls");
        return -1;
    }


    if (strstr(newer,id) != NULL)
    {
        printf ("ID cannot be in passworrd");
        return -1;
    }

    for (int i=0; newer[i] != '\0'; i+=1)
    {
        if (newer[i] != confirm[i])
        {
            printf ("\nMatch Passwords");
            return -1;
        }
    }
    return 1;
}

int main()
{
    char domain[16] = "NUSSTF";
    char id[16] = "a0123456";
    char old[16]= "aaa";
    char newer[16]= "a0123456X";
    char confirm[16]="a0123456X";
    printf ("%s\n%s\n%s\n%s\n%s\n", domain, id, old, newer, confirm);
    /*printf ("Domain:");
    scanf ("%s", &domain);

    printf ("\nUserID:");
    scanf ("%s",&id);

    printf ("\nOld:");
    scanf ("%s", &old);

    printf ("\nNew:");
    scanf ("%s", &newer);

    printf ("\nConfirm:");
    scanf ("%s", &confirm);*/
    int ans;
    ans = isValidPassword (domain, id, old , newer, confirm);
    if (ans ==1)
    {
        printf ("\nPassword changed successfully!");
    }
    else if (ans !=1)
    {
        printf ("\nChange failed!");
    }
    return 0;
}
