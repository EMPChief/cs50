#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user to enter the starting population size (must be greater or equal to 9)
    int starting_size;
    do
    {
        starting_size = get_int("Input an int for starting size: (must be greater or equal to 9) ");
    }
    while (starting_size < 9);

    // Prompt the user to enter the ending population size (must be equal or higher than starting number)
    int ending_size;
    do
    {
        ending_size = get_int("Input ending population: (must be equal or higher than starting number) ");
        
        // If the ending size is less than the starting size, reject the input and prompt the user again
        if (ending_size < starting_size)
        {
            printf("Ending size must be equal or higher than starting size. Please try again.\n");
        }
    }
    while (ending_size < starting_size);

    // Initialize the number of years to 0
    int years = 0;

    // While loop to calculate the number of years the population will take to double in size
    while (starting_size < ending_size)
    {
        // Calculate the population size after one year based on the formula: population = population + (population / 3) - (population / 4)
        starting_size = starting_size + (starting_size / 3) - (starting_size / 4);
        
        // Increment the number of years
        years++;
    }

    // Print the number of years it will take for the population to double in size
    printf("Years: %d\n", years);

    return 0;
}

