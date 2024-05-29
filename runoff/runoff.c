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
bool vote(int voter, int rank, string name); // funksjon så filme stemmer preferansene til.
void tabulate(void);     // Funksjon som teller antall stemmer for hver kandidat.
bool print_winner(void); // Funksjon som skriver ut hvem som vinner.
int find_min(void);      // Funksjon som finner minste antall stemmer.
bool is_tie(int min);    // Funksjon som sjekker om det er en vinner.
void eliminate(int min); // Funksjon som elimerer kandidater med mindre enn minste antall stemmer.

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
    // for loop som går gjennom kvær kandidater og sjekker hvem som er stemt på.
    for (int i = 0; i < candidate_count; i++)
    {
        // if så sjekker hvis kandidaten er valgt.
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // for loop som itererer gjennom alle kandidater og sjekker hvem som er valgt.
    for (int i = 0; i < voter_count; i++)
    {
        // for loop som itererer gjennom alle kandidater og sjekker hvem som er valgt og hvem som
        // ikke er.
        for (int j = 0; j < candidate_count; j++)
        {
            // if statement som sjekker om kandidaten er valgt og hvem som ikke er.
            if (!candidates[preferences[i][j]].eliminated)
            {
                // incrementer kandidatens stemmer.
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // for loop som itererer gjennom alle kandidater og sjekker hvem som vinner.
    for (int i = 0; i < candidate_count; i++)
    {
        // if statement som sjekker om kandidaten har mer enn halvdelen av stemmer.
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    // for loop som itererer gjennom alle kandidater og sjekker hvem som har minste stemmer.
    for (int i = 0; i < candidate_count; i++)
    {
        // if statement som sjekker om kas kandidat så har minste stemmer.
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int remaining_candidate = 0;
    int tied_cand = 0;
    // for loop som itererer gjennom alle kandidater for og sjekk kem så er uavgjort.
    for (int i = 0; i < candidate_count; i++)
    {
        // if statement som sjekker om kandidaten er valgt og hvem som ikke er.
        if (!candidates[i].eliminated)
        {
            remaining_candidate++;
            // if statement som sjekker om kandidaten har lik stemmer.
            if (candidates[i].votes == min)
            {
                tied_cand++;
            }
        }
    }
    return remaining_candidate == tied_cand;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // for loop som itererer gjennom alle kandidater og sjekker hvem som er valgt.
    for (int i = 0; i < candidate_count; i++)
    {
        // if statement som sjekker om kandidaten er eliminert
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
