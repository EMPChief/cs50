#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    // Get user's input
    string s = get_string("Input:  ");
    // Print user's input
    printf("Output: %s\n", s);
    // start for loop to print user's input
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Print user's input
        printf("%c", s[i]);
    }
    // Print new line
    printf("\n");
    // return
    return 0;
}
