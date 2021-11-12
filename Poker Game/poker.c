#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int who_wins(int hand1, int card1, int hand2, int card2)
{
    if (hand1 > hand2)
    {
        return 1;
    }
    else if (hand2 > hand1)
    {
        return 2;
    }
    else if (hand1 == hand2)
    {
        if (card1> card2)
        {
            return 1;
        }
        else if (card2>card1)
        {
            return 2;
        }
        else if (card2==card1)
        {
            return 0;
        }
    }
}

void *type_and_keycard_ranks (int arr[], int *hand_rank, int *card_rank)
{

    int *count;
    int card;

   count = calloc (5, sizeof(int));
    for (int i=0; i<5; i+=1)
    {
        count[i] =1;

        for (int j=i+1; j<5; j+=1)
        {
            if (arr[i] == arr[j])
            {
                count[i] +=1;
            }
        }
    }
    *hand_rank = count[0];
    for (int i=1; i<5; i+=1)
    {
        if (count[i]> *hand_rank)
        {
            *hand_rank = count[i];
        }
    }
    card = arr[0];
    for (int i=0; i<5; i+=1)
    {
        if (*hand_rank == 1)
        {
            if (card < arr[i])
            {
                card = arr[i];
            }
        }
        else
        {
            if (*hand_rank == count[i])
            {
                card = arr[i];
            }
        }
    }
    if (card == 1)
    {
        *card_rank = 13;
    }
    else
    {
        *card_rank = card-1;
    }
    free(count);
}

int main()
{
    int plr1 [5]= {2,2,2,2,11};
    int plr2 [5]= {13,12,12,12,12};
    int card_rank1, card_rank2;
    int hand_rank1, hand_rank2;
    int winner;
    type_and_keycard_ranks (plr1, &hand_rank1, &card_rank1);
    printf ("\nPlayer 1 has hand rank %d and card rank %d", hand_rank1, card_rank1);
    type_and_keycard_ranks(plr2, &hand_rank2, &card_rank2);
    printf ("\nPlayer 2 has hand rank %d and card rank %d", hand_rank2, card_rank2);
    winner = who_wins (hand_rank1, card_rank1, hand_rank2, card_rank2);

    if (winner ==1)
    {
        printf ("\nPlayer 1 Wins.");
    }
    else if (winner ==2)
    {
        printf ("\nPlayer 2 Wins.");
    }
    else
    {
        printf ("\nDraw!");
    }
}
