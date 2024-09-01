#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    // Hent brukerens inndata
    string userInput = get_string("Input:  ");

    // Hent lengden av brukerens inndata
    int inputLength = strlen(userInput);

    // Skriv ut brukerens inndata
    printf("Output: %s\n", userInput);

    // Start en for-løkke for å skrive ut brukerens inndata tegn for tegn
    for (int currentIndex = 0; currentIndex < inputLength; currentIndex++)
    {
        // Skriv ut hvert tegn fra brukerens inndata
        printf("%c", userInput[currentIndex]);
    }

    // Skriv ut en ny linje etter å ha skrevet ut alle tegnene
    printf("\n");

    // Returner 0 for å avslutte programmet med suksessstatuskode (0)
    return 0;
}
