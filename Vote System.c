#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX 9

bool vote(string name);

void print_winner(void);

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;

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
        if (vote(name) == false)
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maximum_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {

        if (candidates[i].votes > maximum_votes)
        {
            maximum_votes = candidates[i].votes;
        }

    }

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == maximum_votes)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    
    return;
}

