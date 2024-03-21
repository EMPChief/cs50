#include <stdio.h>
#include "cs50.h"



int main(void)
{
    // Declare a variable to store the number of scores
    int N;

    // Use a do-while loop to ensure a valid number of scores is entered
    do
    {
        N = get_int("Type how many scores you want to use: ");
    } while (N <= 0);

    // Declare an array to store the scores based on the user-specified number
    int scores[N];

    // Use a for loop to input the scores based on the specified number
    for (int I = 0; I < N; ++I)
    {
        scores[I] = get_int("Score number: ");
    }

    // Initialize a variable to store the sum of the scores
    float sum = 0;

    // Use a for loop to calculate the sum of the scores
    for (int I = 0; I < N; ++I)
    {
        sum += scores[I];
    }

    // Calculate and print the average school grade
    printf("Average school grade is: %f\n", sum / (float)N);

    // Indicate successful completion of the program
    return 0;
}
