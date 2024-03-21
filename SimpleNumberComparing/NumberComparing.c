#include <stdio.h>
#include "cs50.h"

// This program compares two integers input by the user and prints which one is bigger or if they are equal

/*
 * This is the main function of our program.
 * It's the entry point of our program.
 * This function will get two integers from the user
 * and then it will compare them and print the result.
 */
int main(void)
{
    // Prompt the user to enter the first integer
    int a = get_int("What is the a? ");
    
    // Prompt the user to enter the second integer
    int b = get_int("What is the b? ");
    
    // Compare the integers
    if (a > b)
    {
        printf("a is bigger than b\n");
    }
    // Check if a is less than b
    else if (a < b)
    {
        printf("a is less than b\n");
    }
    // Check if a and b are equal
    else
    {
        printf("a and b are equal\n");
    }

    // Return 0 to indicate successful execution
    return 0;
}

