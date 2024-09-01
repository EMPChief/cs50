#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Alloker minne for to strenger
    char *first = malloc(80 * sizeof(char));
    char *second = malloc(80 * sizeof(char));

    // Sjekk om minneallokeringen var vellykket
    if (first == NULL || second == NULL)
    {
        printf("Minneallokering mislyktes.\n");
        return 1;
    }

    // Les inn første streng fra brukeren
    printf("Første streng: ");
    fgets(first, 80, stdin);
    first[strcspn(first, "\n")] = 0; // Fjern linjeskift

    // Les inn andre streng fra brukeren
    printf("Andre streng: ");
    fgets(second, 80, stdin);
    second[strcspn(second, "\n")] = 0; // Fjern linjeskift

    // Sammenlign strengene og skriv ut resultatet
    if (strcmp(first, second) == 0)
    {
        printf("Strengene er like: %s | %s\n", first, second);
    }
    else
    {
        printf("Strengene er forskjellige: %s | %s\n", first, second);
    }

    // Frigjør allokert minne
    free(first);
    free(second);

    return 0;
}