#include <cs50.h>
#include <stdio.h>

// Validate credit card using Luhn’s Algorithm and determine whether it's a VISA, Mastercard or Amex

//SOLUTION

int main(void)
{

    //Get user input
    long int creditCardNumber = get_long("Number:");
    long int creditCardNumberCount = creditCardNumber;

    //Find the number of digits in the creditCardNumber
    int count = 0;
    while (creditCardNumberCount != 0)
    {
        creditCardNumberCount /= 10;
        count++;
    }

    long int remainderOne;
    long int sumSecondDigits = 0;
    long int x = 1;
    double y = 0.1;
    int secondDigit;
    int productDigit;
    int separatedRemainder;
    int separatedDigit;
    int sumProductDigit;

    // Calculate the sum of every second digit in the creditCardNumber
    for (int i = 0; i < count / 2; i++)
    {
        x = x * 100;
        y = y * 100;

        remainderOne = creditCardNumber % x;
        secondDigit = remainderOne / y;
        productDigit = secondDigit * 2;

        // Separate all double digits into single and add them together
        if (productDigit >= 10)
        {
            separatedRemainder = productDigit % 10;
            separatedDigit = productDigit / 10;
            sumProductDigit = separatedRemainder + separatedDigit;

            //Calculate the sum of all second digits if there are double digits
            sumSecondDigits = sumSecondDigits + sumProductDigit;
        }
        else
        {
            //Calculate the sum of all second digits if there are no double digits
            sumSecondDigits = sumSecondDigits + productDigit;
        }
    }

    double z = 0.1;
    double a = 0.01;
    long int remainderTwo;
    int firstDigit;
    int sumFirstDigits = 0;

    // Calculate the sum of the remaining digits in the creditCardNumber
    for (int i = 0; i <= count / 2; i++)
    {
        z = z * 100;
        a = a * 100;
        long int b = z;

        remainderTwo = creditCardNumber % b;
        firstDigit = remainderTwo / a;
        sumFirstDigits = sumFirstDigits + firstDigit;
    }

    //Calculate the total sum
    int sum;
    sum = sumSecondDigits + sumFirstDigits;

    //Get the first two or 1 digit for each type of credit card
    int AmericanExpress = creditCardNumber / 10000000000000;
    int MasterCard = creditCardNumber / 100000000000000;
    int Visa13 = creditCardNumber / 1000000000000;
    int Visa16 = creditCardNumber / 1000000000000000;

    //Print INVALID if credit card number provided is not valid
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (count == 15 && (AmericanExpress == 34 || AmericanExpress == 37))
    {
        printf("AMEX\n");
    }

    else if (count == 16 && (MasterCard > 50 && MasterCard < 56))
    {
        printf("MASTERCARD\n");
    }

    else if ((count == 13 || count == 16) && (Visa13 == 4 || Visa16 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}