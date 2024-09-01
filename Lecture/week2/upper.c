#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Hent brukerens inndata
    string userInput = get_string("Before: ");

    // Skriv ut teksten etter konvertering
    printf("After: ");

    // Start en for-løkke for å skrive ut brukerens inndata med store bokstaver
    for (int currentIndex = 0, length = strlen(userInput); currentIndex < length; currentIndex++)
    {
        // Konverter hvert tegn til store bokstaver og skriv det ut
        printf("%c", toupper(userInput[currentIndex]));
    }

    // Skriv ut en ny linje etter å ha skrevet ut hele teksten
    printf("\n");

    return 0;
}
