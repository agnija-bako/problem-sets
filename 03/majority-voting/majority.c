#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Implement a solution that runs a relative/simple majority voting (plurality-voting) election

//SOLUTION

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //Compare candidate i name to name
        if (strcmp(name, candidates[i].name) == 0)
        {
            //Add a vote to the candidate i that matches with name
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    candidate winner = candidates[0];

    //Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //Compare the candidate i with the winner
        if (candidates[i].votes > winner.votes)
        {
            //If candidate i has more votes, it becomes the winner
            winner = candidates[i];
        }
    }

    // Print winner
    printf("%s\n", (string) winner.name);

    //Loop through all candidates again to  find more winners if there
    for (int j = 0; j < candidate_count; j++)
    {
        // If candidate j has same number of votes and is not the same candidate as winner, print their name
        if (candidates[j].votes == winner.votes && candidates[j].name != winner.name)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    return;
}

