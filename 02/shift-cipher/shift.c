#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Implement a solution that encrypts messages using Shift cipher (Caesar cipher)

//SOLUTION

void plainToChipher(string plaintext, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./shift key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./shift key\n");
            return 1;
        }
    }

    //Define key
    int k = atoi(argv[1]);
    //Get plaintext
    string plaintext = get_string("plaintext: ");
    //Convert plaintext to ciphertext
    plainToChipher(plaintext, k);



}

void plainToChipher(string plaintext, int k)
{
    int p = 0;
    int c = 0;
    int ascii = 0;
    char cipher;

    printf("ciphertext: ");

    //Loop through the plaintext string characters
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Check if letter is uppercase
        if (isupper(plaintext[i]))
        {
            //Convert letter where A starts from 0
            p = (int) plaintext[i] - 65;
            //Execute shift algorithm
            c = (p + k) % 26;
            //Convert letter back to ASCII with the new value
            ascii = c + 65;
            //Convert ASCII to letter
            cipher = (char) ascii;
            printf("%c", cipher);


        }

        //Check if letter is lower case
        else if (islower(plaintext[i]))
        {
            //Convert letter where a starts from 0
            p = (int) plaintext[i] - 97;
            // Execute shift algorithm
            c = (p + k) % 26;
            //Convert letter back to ASCII with the new value
            ascii = c + 97;
            //Convert ASCII to letter
            cipher = (char) ascii;
            printf("%c", cipher);

        }

        else if (ispunct(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }

        else if (isspace(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }

    }

    printf("\n");

}