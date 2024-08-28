#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    // Get input string from user
    char *inputString = get_string("Before: ");
    if (inputString == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for the output string
    char *outputString = malloc(strlen(inputString) + 1);
    if (outputString == NULL)
    {
        printf("Memory allocation failed.\n");
        free(inputString);
        return 2;
    }

    // Copy the input string to the output string
    strcpy(outputString, inputString);
    
    // Capitalize the first character of the output string if it is not empty
    if (strlen(outputString) > 0)
    {
        outputString[0] = toupper(outputString[0]);
    }

    // Print the result
    printf("After: %s\n", outputString);

    // Free allocated memory
    free(outputString);
    free(inputString);

    return 0;
}
