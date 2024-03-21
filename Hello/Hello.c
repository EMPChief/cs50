#include <stdio.h>
#include "cs50.h"

// Main function
int main(void)
{
    // Prompt user for their name
    string name = get_string("What's your name? ");
    
    // Print a personalized greeting
    printf("Hello there %s\n", name);
}

