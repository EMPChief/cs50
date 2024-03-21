#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Called by main to begin the program
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // printing the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // if player 2 wins
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // if tie
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    // compute and return score for string passed as parameter
    int score = 0;
    // start for loop to compute score
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // check if letter is upper or lower
        if (isupper(word[i]))
        {
            // add score based on letter position in alphabet (1-26)
            score += POINTS[word[i] - 'A'];
        }
        // if letter is lower case 
        else if (islower(word[i]))
        {
            // add score based on letter position in alphabet (1-26)
            score += POINTS[word[i] - 'a'];
        }
    }
    // return score
    return score;

}
