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
        if (isalpha(newer[i])!= 0) 
        {
            if (newer[i] >= 'A' && newer[i]<= 'Z' ) 
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
        printf ("\nPlease have both capital letters and small letters!");
        return -1;
    }


    if (strstr(newer,id) != NULL)
    {
        printf ("ID cannot be in password");
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
    char domain[16];
    char id[16];
    char old[16];
    char newer[16];
    char confirm[16];
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
    
    isValidPassword (domain, id, old , newer, confirm);
    if (isValidPassword)
    {
        printf ("\nPassword changed successfully!");
    }
    else 
    {
        printf ("\nChange failed!");
    }
    return 0;
}
