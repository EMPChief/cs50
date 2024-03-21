#include <stdio.h>
#include "cs50.h"
#include <string.h>


int main(void)
{
    // Get user's name
    string name = get_string("What's your name? ");
    // Get length of name
    int length = strlen(name);
    // Print length
    printf("Length: %i\n", length);
}

