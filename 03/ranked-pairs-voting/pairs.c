#include <cs50.h>
#include <stdio.h>
#include <string.h>


//CODE PROVIDED IN THE TASK

//--------------------------------------------------------------

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_cycle(int loser, int winner);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: preferences [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

//--------------------------------------------------------------

//SOLUTION

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop through all candidates to find the matching name
    for (int i = 0; i < candidate_count; i++)
    {
        //If candidate name matches with name, then ranks[rank] equals the candidate from the candidate array
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            //printf("this is rank %i\n", ranks[rank]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //Count elements in the prefered array
    int n;

    //Loop through every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //Loop through all ranks and check if the rank[j] equals the candidate
        for (int j = 0; j < candidate_count; j++)
        {
            //If rank equals to candidate, the value is 0
            if (ranks[j] == i)
            {
                preferences[i][j] = preferences[i][j] + 0;

                //Loop through remaining candidates and add 1, as candidate i is prefered over candidate z
                for (int z = j + 1; z < candidate_count; z++)
                {
                    n = ranks[z];
                    preferences[i][n] = preferences[i][n] + 1;
                }
                break;
            }
            // If rank doesn't equal candidate, add 0, it yet has not preference over others
            else
            {
                preferences[i][j] = preferences[i][j] + 0;

            }
        }
    }


    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int position = 0;

    //Loop through the first set of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //Loop through the second set of candidates for comparison
        for (int j = i + 1; j < candidate_count; j++)
        {

            if (preferences[i][j] != preferences[j][i])
            {
                //If candidates1 and 2 are not equal add the winner and loser to the pairs array and add to the pair_count
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[position].winner = i;
                    pairs[position].loser = j;
                    pair_count = pair_count + 1;
                }
                else if (preferences[i][j] < preferences[j][i])
                {
                    pairs[position].winner = j;
                    pairs[position].loser = i;
                    pair_count = pair_count + 1;

                }
                //Change pairs array position to not replace other elements in the array
                position = position + 1;
            }
        }
    }

    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    pair temp;
    int winner1_score;
    int winner2_score;
    int position;
    //Loop through all [i] candidates in the pairs array
    for (int i = 0; i < pair_count; i++)
    {
        position = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            winner1_score = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            winner2_score = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

            //How many people prefered the winner in the pair - strenght of victory
            if (winner1_score < winner2_score)
            {
                position = j;
            }
        }

        if (position != i)
        {
            temp = pairs[i];
            pairs[i] = pairs[position];
            pairs[position] = temp;
        }

    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //Loop through all pairs
    for (int i = 0; i < pair_count; i++)
    {
        //If no cycles are detected, set locked pairs array to true
        if (is_cycle(pairs[i].loser, pairs[i].winner) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

bool is_cycle(int loser, int winner)
{
    int new_loser;
    bool cycle = false;

    //Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //Find a loser candidate to the pairs[i].loser
        if (locked[loser][i] == true)
        {
            //Check if the loser of the loser candidate is the original pairs winner
            if (i == winner)
            {
                cycle = true;
                break;
            }
            else
            {
                new_loser = i;
                cycle = is_cycle(new_loser, winner);
            }
        }

    }

    return cycle;
}

// Print the winner of the election
void print_winner(void)
{
    int no_edges = 0;
    int winner;
    // Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            //Check if candidate i loses to anyone in the locked array
            if (locked[j][i] == true)
            {
                break;
            }
            else
            {
                //Find the candidate that no one is pointing to
                no_edges = no_edges + 1;
                if (no_edges == candidate_count)
                {
                    winner = i;
                }
            }
        }

        no_edges = 0;
    }
    printf("%s\n", candidates[winner]);
    return;
}

