#include "cs50.h"
#include <stdio.h>
#include <string.h>

// Hovedfunksjon
int main(void)
{
    // Hent brukerens inndata
    string phrase = get_string("Skriv inn en setning: ");

    // Hent lengden av setningen
    int length = strlen(phrase);

    // Sjekk om setningen er i alfabetisk rekkefølge
    bool isAlphabeticOrder = true;

    // Start en for-løkke for å sjekke om setningen er i alfabetisk rekkefølge
    for (int currentIndex = 0; currentIndex < length - 1; currentIndex++)
    {
        // Sjekk om setningen er i alfabetisk rekkefølge med en if-setning
        if (phrase[currentIndex] > phrase[currentIndex + 1])
        {
            // Sett isAlphabeticOrder til false og bryt løkken for å avslutte programmet
            isAlphabeticOrder = false;
            break;
        }
    }

    // Skriv ut om setningen er i alfabetisk rekkefølge eller ikke
    printf("Setningen '%s' er %s i alfabetisk rekkefølge\n", phrase, isAlphabeticOrder ? "" : "ikke ");
}
