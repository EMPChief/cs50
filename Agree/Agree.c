#include <stdio.h>
#include <string.h>
#include "cs50.h"

// Main function
int main(void)
{
    // Declare a character array to store the user's input
    char c[4];

    // Prompt the user for input
    printf("Do you agree? ");

    // Scan the user's input into the character array
    scanf("%s", c);

    // Check if the user agrees
    if (strcmp(c, "y") == 0 || strcmp(c, "Y") == 0 || strcmp(c, "yes") == 0 || strcmp(c, "Yes") == 0 || strcmp(c, "YES") == 0)
    {
        // Print a message indicating the user agrees
        printf("So you do agree\n");
    }
    // Check if the user does not agree
    else if (strcmp(c, "n") == 0 || strcmp(c, "N") == 0 || strcmp(c, "no") == 0 || strcmp(c, "No") == 0 || strcmp(c, "NO") == 0)
    {
        // Print a message indicating the user does not agree
        printf("So you don't agree\n");
    }
    // If the user's input is not valid
    else
    {
        // Print a message indicating invalid input
        printf("Invalid\n");
    }

    // Return 0 to indicate successful program execution
    return 0;
}

