#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
#include <time.h>
void repdigit();
void interest();
void deal();
int main()
{

    // repdigit();
    // interest();
    deal();
    return 0;
}

void repdigit()
{
    bool digit_seen[10] = {false};
    int digit;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        if (digit_seen[digit])
        {
            break;
        }
        digit_seen[digit] = true;
        n /= 10;
    }
    if (n > 0)
    {
        printf("Repeated digit.\n");
    }
    else
    {
        printf("No repeated digit.\n");
    }
}

void interest()
{
    int rate, year;
    double rates[5];
    printf("Enter interest rate: ");
    scanf("%d", &rate);
    printf("Enter number of years: ");
    scanf("%d", &year);
    int balance = 100;
    printf("%10s", "years");
    for (int i = 0; i < (int)(sizeof(rates) / sizeof(rates[0])); i++)
    {
        rates[i] = balance + rate + i;
        printf("%10d%%", rate + i);
    }
    printf("\n");
    for (int i = 1; i <= year; i++)
    {
        printf("%10d", i);
        for (int j = 0; j < (int)(sizeof(rates) / sizeof(rates[0])); j++)
        {
            printf("%10.2f%%", rates[j]);
            rates[j] *= (balance + rate + j) / 100.0;
        }
        printf("\n");
    }
}

#define NUM_SUITS 4
#define NUM_RANKS 13
void deal()
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    const char rank_code[NUM_RANKS] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    const char suit_code[NUM_SUITS] = {'c', 'd', 'h', 's'};
    srand((unsigned)(time(NULL)));

    int num_cards, rank, suit;
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (in_hand[suit][rank])
        {
            continue;
        }
        printf("%c%c ", suit_code[suit], rank_code[rank]);
        in_hand[suit][rank] = true;
        --num_cards;
    }
    printf("\n");
}