#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Poeng tildelt hver bokstav i alfabetet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Funksjon for å beregne poeng for et ord
int compute_score(string word);

int main(void)
{
    // Hent inndata fra begge spillere
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Beregn poeng for begge ord
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Skriv ut vinneren
    if (score1 > score2)
    {
        printf("Player 1 wins with %i points!\n", score1);
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins with %i points!\n", score2);
    }
    else
    {
        printf("It's a tie with %i points each!\n", score1);
    }

    return 0;
}

int compute_score(string word)
{
    int score = 0;

    // Gå gjennom hvert tegn i ordet
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Konverter tegn til store bokstaver
        char c = toupper(word[i]);

        // Hvis tegnet er en bokstav, beregn poeng
        if (c >= 'A' && c <= 'Z')
        {
            // Finn indeksen i POINTS arrayet og legg til poeng
            score += POINTS[c - 'A'];
        }
    }

    return score;
}
