#include "cs50.h"
#include <stdio.h>
#include <string.h>

// Main function
int main(void)
{
    // Get user's input
    string phrase = get_string("Input a phrase: ");
    // Get length of phrase
    int length = strlen(phrase);
    // Check if phrase is alphabetic order
    bool isAlphabeticOrder = true;
    // Start for loop to check if phrase is alphabetic order
    for (int i = 0; i < length - 1; i++)
    {
        // Check if phrase is alphabetic order using if statement
        if (phrase[i] > phrase[i + 1])
        {
            // Print if phrase is not alphabetic order and break for loop to end program
            isAlphabeticOrder = false;
            break;
        }
    }
    // Print if phrase is alphabetic order
    printf("The phrase '%s' is %s an alphabetic order\n", phrase, isAlphabeticOrder ? "" : "not ");
}

