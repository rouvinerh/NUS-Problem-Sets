void decrypt (char message[], char *result)
{
    int length;
    length = strlen(message);

    for (int i=0; i<length;i+=1)
    {
        int current = message[i];
        if (islower(message[i])!=0 && (current-'a')-13 <0)
        {
            int key = ((current-'a')-13)%26;
            result[i] = current - key;
        }
        else if (islower(message[i])==0 && (current-'A')-13<0)
        {
            int key = ((current-'A')-13)%26;
            result[i] = current - key;
        }
        else
        {
            result[i] = current - 13;
        }
    }
    printf ("\nDecrypted Message: %s", result);


}

void encrypt (char message[], char *result)
{
    int length;
    length = strlen(message);

    for (int i=0; i<length;i+=1)
    {
        int current = message[i];
        if (islower(message[i])!=0 && (current - 'a')+13 >26)
        {
            int key = ((current - 'a')+13) %26;
            result[i] = current + key;
        }
        else if (islower(message[i])==0 && (current - 'A')+13>26)
        {
            int key = ((current - 'A')+13) %26;
            result[i] = current + key;
        }
        else
        {
            result[i] = current+13;
        }
    }

    printf ("\nEncrypted Message: %s", result);
}

int main()
{
    int process;
    char message[100];
    char *result;

    printf ("Enter 1 or 2:");
    scanf ("%d", &process);
    printf ("\nEnter message:");
    scanf ("%s", &message);

    if (process ==1)
    {
        encrypt(message, &result);
    }
    if (process ==2)
    {
        decrypt (message, &result);
    }
    return 0;
}
