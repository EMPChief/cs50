#include <stdio.h>
#include "cs50.h"

// Declare variables
int N; // Number of scores
int scores[100]; // Array to store scores
float sum = 0; // Variable to store the sum of scores

int main(void)
{
    // Prompt user for number of scores and validate input
    do
    {
        N = get_int("Type how many scores you want to use: ");
    }while (N <= 0);

    // Loop to get scores from user
    for (int I = 0; I < N; ++I)
    {
        scores[I] = get_int("Score number: ");
    }

    // Calculate sum of scores
    for (int I = 0; I < N; ++I)
    {
        sum += scores[I];
    }

    // Print average score
    printf("Average score is: %f\n", sum / N);
    
    // Indicate successful completion
    return 0;

}
