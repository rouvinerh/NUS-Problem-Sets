bool isPalindrome (char word[], int size)
{
    int answer=1;;

    for (int i=0; i<size; i+=1)
    {
        if ((toupper(word[i])) != toupper(word[size- i-1]))
        {
            answer =0;
            break;
        }


    }
    if (answer ==0)
    {
        return false;
    }
    else if (answer ==1)
    {
        return true;
    }
}

int main(){

    int size;
    char word[21];
    printf ("Enter word:");
    scanf ("%s", &word);

    size = strlen(word);
    printf ("\nSize = %d", size);
    int ans = isPalindrome (word, size);
    if (ans ==1)
    {
        printf ("\n%s is a palindrome",word);
    }
    else if (ans ==0)
    {
        printf ("\n%s is not a palindrome", word);
    }


}
