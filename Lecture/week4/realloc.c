#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Allokerer minne for en streng med plass til 6 tegn (5 tegn + null-terminator)
    char *hello = malloc(6 * sizeof(char));
    if (hello == NULL)
    {
        // Hvis minneallokeringen feiler, skriv ut en feilmelding og avslutt programmet
        fprintf(stderr, "Minneallokering mislyktes\n");
        return 1;
    }

    // Kopierer strengen "Hello" til den allokerte minneplassen
    strcpy(hello, "Hello");
    // Skriver ut strengen
    printf("%s\n", hello);

    // Reallokerer minne for å gi plass til en lengre streng (11 tegn: "Hello World")
    hello = realloc(hello, 11 * sizeof(char));
    if (hello == NULL)
    {
        // Hvis minne-reallokeringen feiler, skriv ut en feilmelding og avslutt programmet
        fprintf(stderr, "Minne-reallokering mislyktes\n");
        return 1;
    }

    // Legger til " World" til den eksisterende strengen
    strcat(hello, " World");
    // Skriver ut den oppdaterte strengen
    printf("%s\n", hello);

    // Frigjør det allokerte minnet
    free(hello);
    return 0;
}
