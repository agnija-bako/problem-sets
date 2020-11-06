#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

//Task: Calculate the approximate grade level needed to comprehend a text (Coleman-Liau index) the provided by the user

//SOLUTION

void readingLevel(string text);
void calculateGrade(int letters, int words, int sentences);


int main(void)
{
    //Get user input
    string text = get_string("Text:");

    readingLevel(text);

}


void readingLevel(string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // Calculate all the letters in the text
        if (isalpha(text[i]))
        {
            letters = letters + 1;

            //If at least one letter was found, we set word to 1
            if (letters == 1)
            {
                words = 1;
            }
        }

        // Calculate all the words in the text
        if (isspace(text[i]))
        {

            words = words + 1;

        }

        // Calculate all the sentences in the text
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences = sentences + 1;

        }
        
    }
    
    if(letters>0)
    {
        calculateGrade(letters, words, sentences);    
    }
    
}


void calculateGrade(int letters, int words, int sentences)
{
    // Calculate the average number of letters per 100 words in the text
    float L = ((float) letters / (float) words) * 100;


    // Calculate the average number of sentences per 100 words in the text
    float S = ((float) sentences / (float) words) * 100;


    // Calculate Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");

    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }

}