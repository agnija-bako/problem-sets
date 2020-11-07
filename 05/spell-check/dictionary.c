// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

//SOLUTION

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int number;

// Number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Get the hash for the word to be checked
    int index = hash(word);
    //Loop through the linked list at the hash position with cursor
    node *cursor = table[index];
    while (cursor != NULL)
    {
        //Check if the string in dictionary and the given text are the same
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Source djb2 by Dan Bernstein - https://gist.github.com/MohamedTaha98/ccdf734f13299efb73ff0b12f7ce429f
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open the dicutionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char new_word[45];

    //Loop the file and load all its contents into the a hash table
    while (fscanf(file, "%s", new_word) != EOF)
    {
        //Alocate space for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //Fill the new node
        strcpy(n->word, new_word);
        n->next = NULL;
        //Get the hash for new_word
        int index = hash(new_word);

        //Check if table[index] is pointing at anything already
        if (table[index] == NULL)
        {
            table[index] = n;

            number = number + 1;
        }

        else
        {
            //Make the new node point to the head
            n->next = table[index];
            //Make table[index] point to the new head
            table[index] = n;
            number = number + 1;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return number;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor;
    node *temp;
    //Loop through all table nodes
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        else
        {
            //Set cursor to move from the head of linked list and temp to follow it
            cursor = table[i];
            temp = cursor;
            while (temp != NULL)
            {
                //Free temp until temp reaches null - the end of the list
                temp = cursor;
                if (cursor != NULL)
                {
                    cursor = cursor->next;
                }
                free(temp);
            }
        }
    }
    return true;
}
