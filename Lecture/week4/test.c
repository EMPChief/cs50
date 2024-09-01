#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    // Hent input-streng fra bruker
    char *inputString = get_string("Før: ");

    // Sjekk at minneallokeringen lykkes
    if (inputString == NULL)
    {
        printf("Minneallokering mislyktes.\n");
        return 1;
    }

    // Alloker minne for utdata-strengen
    char *outputString = malloc(strlen(inputString) + 1); // +1 for null-terminator
    // Sjekk at minneallokeringen lykkes
    if (outputString == NULL)
    {
        printf("Minneallokering mislyktes.\n");
        free(inputString); // Frigjør minnet for input-strengen før vi avslutter
        return 2;
    }

    // Kopier input-strengen til utdata-strengen
    strcpy(outputString, inputString);

    // Kapitaliser det første tegnet av utdata-strengen hvis den ikke er tom
    if (strlen(outputString) > 0)
    {
        outputString[0] = toupper(outputString[0]);
    }

    // Skriv ut resultatet
    printf("Etter: %s\n", outputString);

    // Frigjør allokert minne
    free(outputString);
    free(inputString);

    return 0;
}
