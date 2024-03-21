#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Get user's input
    string s = get_string("Before: ");
    // Print user's input
    printf("After: ");
    // start for loop to print user's input
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Print user's input
        printf("%c", toupper(s[i]));
    }
    // Print new line
    printf("\n");
}