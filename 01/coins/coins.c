#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Return a minimum number of coins to be returned as change to the user

// SOLUTION

int main(void)
{
    //Get user input
    float change;
    do
    {
        change = get_float("Change owed:\n");
    } while (change < 0);

    //Convert dollars into cents
    int cents = round(change * 100);

    int coins = 0;
    int newRemainder = cents;

    //Count all possible 25 cents
    while (newRemainder >= 25)
    {
        newRemainder = newRemainder - 25;
        coins = coins + 1;
    }

    //Count all possible 10 cents
    while (newRemainder >= 10)
    {
        newRemainder = newRemainder - 10;
        coins = coins + 1;
    }

    //Count all possible 5 cents
    while (newRemainder >= 5)
    {
        newRemainder = newRemainder - 5;
        coins = coins + 1;
    }

    //Count all possible 1 cents
    while (newRemainder >= 1)
    {
        newRemainder = newRemainder - 1;
        coins = coins + 1;
    }

    printf("%i", coins);
}
