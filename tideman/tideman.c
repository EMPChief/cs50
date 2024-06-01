#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(
    int rank, string name,
    int ranks[]); // sjekker om kandidatens navn er gyldig og oppdaterer ranks-arrayet tilsvarende
void record_preferences(
    int ranks[]); // oppdaterer det globale preferences-arrayet basert på en velgers rangeringer
void add_pairs(
    void); // legger til alle par av kandidater der en er foretrukket over den andre i pairs-arrayet
void sort_pairs(void);   // sorterer parene i synkende rekkefølge etter seiersmargin
void lock_pairs(void);   // låser parene uten å skape sykler i grafen
void print_winner(void); // skriver ut vinneren av valget, som er kilden i grafen

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // For-løkke som itererer gjennom alle kandidater og sjekker hvem som er stemt på.
    for (int candidateIndex = 0; candidateIndex < candidate_count; candidateIndex++)
    {
        // If-setning som sjekker om kandidatens navn er gyldig og oppdaterer ranks-arrayet.
        if (strcmp(name, candidates[candidateIndex]) == 0)
        {
            ranks[rank] = candidateIndex;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // For-løkke som itererer gjennom alle kandidater og oppdaterer preferences-arrayet.
    for (int firstCandidateIndex = 0; firstCandidateIndex < candidate_count - 1;
         firstCandidateIndex++)
    {
        // Indre for-løkke som itererer gjennom de resterende kandidatene og oppdaterer
        // preferences-arrayet.
        for (int secondCandidateIndex = firstCandidateIndex + 1;
             secondCandidateIndex < candidate_count; secondCandidateIndex++)
        {
            // Øker antall preferanser for kandidaten ranks[firstCandidateIndex] over kandidaten
            // ranks[secondCandidateIndex].
            preferences[ranks[firstCandidateIndex]][ranks[secondCandidateIndex]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int strength_of_candidate;

    // For-løkke som itererer gjennom alle kandidater, bortsett fra den siste.
    for (int firstCandidateIndex = 0; firstCandidateIndex < candidate_count - 1;
         firstCandidateIndex++)
    {
        // indre for-løkke som itererer gjennom alle kandidater som kommer etter den nåværende
        // kandidaten.
        for (int secondCandidateIndex = firstCandidateIndex + 1;
             secondCandidateIndex < candidate_count; secondCandidateIndex++)
        {
            // Beregn styrken av preferanse mellom to kandidater.
            strength_of_candidate = preferences[firstCandidateIndex][secondCandidateIndex] -
                                    preferences[secondCandidateIndex][firstCandidateIndex];

            // Hvis første kandidat er foretrukket over andre kandidat.
            if (strength_of_candidate > 0)
            {
                pairs[pair_count].winner = firstCandidateIndex;
                pairs[pair_count].loser = secondCandidateIndex;
                pair_count++;
            }
            // Hvis andre kandidat er foretrukket over første kandidat.
            else if (strength_of_candidate < 0)
            {
                pairs[pair_count].winner = secondCandidateIndex;
                pairs[pair_count].loser = firstCandidateIndex;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // For-løkke som itererer gjennom alle kandidatindekser, unntatt den siste
    for (int candidate_index = 0; candidate_index < pair_count - 1; candidate_index++)
    {
        // Antar at den sterkeste kandidatindeksen er den gjeldende kandidatindeksen
        int strongest_candidate_index = candidate_index;
        // indre for-løkke som itererer gjennom alle sammenligningsindekser som er etter den
        // gjeldende kandidatindeksen
        for (int compare_index = candidate_index + 1; compare_index < pair_count; compare_index++)
        {
            // Beregn styrken til den gjeldende kandidaten og den sterkeste kandidaten
            int current_strength =
                preferences[pairs[compare_index].winner][pairs[compare_index].loser] -
                preferences[pairs[compare_index].loser][pairs[compare_index].winner];
            int strongest_strength = preferences[pairs[strongest_candidate_index].winner]
                                                [pairs[strongest_candidate_index].loser] -
                                     preferences[pairs[strongest_candidate_index].loser]
                                                [pairs[strongest_candidate_index].winner];
            // if statment som sjekker om den gjeldende kandidaten er sterkere enn den sterkeste
            // kandidaten
            if (current_strength > strongest_strength)
            {
                strongest_candidate_index = compare_index;
            }
        }
        // if statment som sjekker om par hvis den sterkeste kandidatindeksen ikke er den gjeldende
        // kandidatindeksen
        if (strongest_candidate_index != candidate_index)
        {
            pair temp = pairs[candidate_index];
            pairs[candidate_index] = pairs[strongest_candidate_index];
            pairs[strongest_candidate_index] = temp;
        }
    }
}

// Check for cycle in the graph
bool has_cycle(int candidate_winner, int candidate_loser)
{
    // Sjekker om det er dannet en syklus ved å sjekke om kandidaten blir valgt.
    if (candidate_winner == candidate_loser)
    {
        return true;
    }

    // Går gjennom alle kandidater for å se om det er en syklus.
    for (int current_candidate = 0; current_candidate < candidate_count; current_candidate++)
    {
        // Sjekker om kandidaten er låst til den gjeldende kandidaten.
        if (locked[candidate_loser][current_candidate])
        {
            // Sjekker om det er en syklus med den gjeldende kandidaten.
            if (has_cycle(candidate_winner, current_candidate))
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Går gjennom alle par av kandidater.
    for (int current_pair = 0; current_pair < pair_count; current_pair++)
    {
        // Sjekker om det dannes en syklus ved å legge til dette paret.
        if (!has_cycle(pairs[current_pair].winner, pairs[current_pair].loser))
        {
            locked[pairs[current_pair].winner][pairs[current_pair].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // For-løkke som itererer gjennom alle kandidater.
    for (int candidate_index = 0; candidate_index < candidate_count; candidate_index++)
    {
        // Variabel som sjekker om kandidaten har åpen på kandidatenes plats.
        bool has_locks = false;

        // Indre for-løkke som itererer gjennom alle kandidater som er på kandidatenes plats.
        for (int locked_index = 0; locked_index < candidate_count; locked_index++)
        {
            // If-setning som sjekker om kandidaten er på kandidatenes plats ved å se etter låser.
            if (locked[locked_index][candidate_index] == true)
            {
                has_locks = true;
                break;
            }
        }

        // If-setning som sjekker om kandidaten ikke har låser, noe som betyr de er vinneren.
        if (!has_locks)
        {
            printf("%s\n", candidates[candidate_index]);
            return;
        }
    }
    return;
}
