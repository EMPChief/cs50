#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name); // Funksjon som registrerer stemmer for preferanser.
void tabulate(void);     // Funksjon som teller antall stemmer for hver kandidat.
bool print_winner(void); // Funksjon som skriver ut hvem som vinner.
int find_min(void);      // Funksjon som finner minste antall stemmer.
bool is_tie(int min);    // Funksjon som sjekker om det er uavgjort.
void eliminate(int min); // Funksjon som eliminerer kandidater med minst antall stemmer.

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // For-løkke som går gjennom hver kandidat og sjekker hvem som er stemt på.
    for (int candidate_index = 0; candidate_index < candidate_count; candidate_index++)
    {
        // If-setning som sjekker om kandidaten er valgt.
        if (strcmp(name, candidates[candidate_index].name) == 0)
        {
            preferences[voter][rank] = candidate_index;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // For-løkke som itererer gjennom alle velgere.
    for (int voter_index = 0; voter_index < voter_count; voter_index++)
    {
        // For-løkke som itererer gjennom alle preferanser for hver velger.
        for (int rank_index = 0; rank_index < candidate_count; rank_index++)
        {
            // If-setning som sjekker om kandidaten ikke er eliminert.
            if (!candidates[preferences[voter_index][rank_index]].eliminated)
            {
                // Øker kandidatens stemmetall.
                candidates[preferences[voter_index][rank_index]].votes++;
                break;
            }
        }
    }
    return;
}


// Print the winner of the election, if there is one
bool print_winner(void)
{
    // For-løkke som itererer gjennom alle kandidater og sjekker om noen har vunnet.
    for (int candidate_index = 0; candidate_index < candidate_count; candidate_index++)
    {
        // If-setning som sjekker om kandidaten har mer enn halvparten av stemmene.
        if (candidates[candidate_index].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[candidate_index].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    // For-løkke som itererer gjennom alle kandidater og finner den med minst stemmer.
    for (int candidate_index = 0; candidate_index < candidate_count; candidate_index++)
    {
        // If-setning som sjekker hvilken kandidat som har minst stemmer og ikke er eliminert.
        if (!candidates[candidate_index].eliminated && candidates[candidate_index].votes < min)
        {
            min = candidates[candidate_index].votes;
        }
    }
    return min;
}


// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int remaining_candidate_count = 0;
    int tied_candidate_count = 0;
    // For-løkke som itererer gjennom alle kandidater for å sjekke om det er uavgjort.
    for (int candidate_index = 0; candidate_index < candidate_count; candidate_index++)
    {
        // If-setning som sjekker om kandidaten ikke er eliminert.
        if (!candidates[candidate_index].eliminated)
        {
            remaining_candidate_count++;
            // If-setning som sjekker om kandidaten har like mange stemmer som minstestemmene.
            if (candidates[candidate_index].votes == min)
            {
                tied_candidate_count++;
            }
        }
    }
    return remaining_candidate_count == tied_candidate_count;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // For-løkke som itererer gjennom alle kandidater og eliminerer de med minst stemmer.
    for (int candidate_index = 0; candidate_index < candidate_count; candidate_index++)
    {
        // If-setning som sjekker om kandidaten har minst antall stemmer og eliminerer dem.
        if (candidates[candidate_index].votes == min)
        {
            candidates[candidate_index].eliminated = true;
        }
    }
    return;
}