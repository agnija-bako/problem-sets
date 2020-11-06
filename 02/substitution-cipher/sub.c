#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//Implement a solution that encrypts user provided text using substitution cipher

//SOLUTION

void plainToCipher(string key, string plaintext);

int main(int argc, string argv[])
{
    //Validate only 1 command line argument
    if (argc != 2)
    {
        printf("./sub key");
        return 1;
    }

    //Validate key lenght
    if (strlen(argv[1]) != 26)
    {
        printf("key should be 26 characters");
        return 1;
    }

    //Validate for non-alphabetic characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("key must contain only alphabetic characters");
            return 1;
        }
        //Validate for repeated characters
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                printf("key must contain all unique characters");
                return 1;

            }
        }

    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");

    //Call plainToCipher to print the ciphertext
    plainToCipher(key, plaintext);


}

void plainToCipher(string key, string plaintext)
{
    int x;
    char cipher;
    char cipherLower;
    char cipherUpper;

    printf("ciphertext: ");

    // Loop through the plaintext string
    for (int i = 0; i < strlen(plaintext); i++)
    {
        //Check if char[i] is uppercase
        if (isupper(plaintext[i]))
        {
            // calculate the alphabetical value(0-26) of i char
            x = plaintext[i] - 65;
            //Assign alphabetical value equal to the array value of argv (A = 0 = x)
            cipher = key[x];

            //Check if cipher is lower key
            if (islower(cipher))
            {
                //Fix cipher to be upper key
                cipherUpper = cipher - 32;

                //Store cipher in a ciphertext array variable
                printf("%c", cipherUpper);


            }

            else
            {
                //Store cipher in a ciphertext array variable
                printf("%c", cipher);
            }
        }
        //Check if char i is lowercase
        else if (islower(plaintext[i]))
        {
            //Calculate the alphabetical value of i char
            x = plaintext[i] - 97;
            // Assign alphabetical value equal the key array value
            cipher = key[x];
            //If cipher is uppercase for a lowercase plaintext, make it lowercase and store value in ciphertext array
            if (isupper(cipher))
            {
                cipherLower = cipher + 32;
                //ciphertext[i] = cipherLower;
                printf("%c", cipherLower);

            }

            else
            {
                //ciphertext[i] = cipher;
                printf("%c", cipher);
            }

        }

        // See if char i is a space, add it to the ciphertext array
        else if (isspace(plaintext[i]))
        {
            cipher = plaintext[i];
            //ciphertext[i] = cipher;
            printf("%c", cipher);
        }

        //See if char i is a punctuation, add to the cipher array
        else if (ispunct(plaintext[i]))
        {
            cipher = plaintext[i];
            //ciphertext[i] = cipher;
            printf("%c", cipher);
        }
        else if (isdigit(plaintext[i]))
        {
            cipher = plaintext[i];
            //ciphertext[i] = (int) cipher;
            printf("%c", cipher);
        }
    }
    printf("\n");
}