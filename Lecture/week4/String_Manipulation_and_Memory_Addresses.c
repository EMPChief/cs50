#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Initialiserer en streng med hilsenen
    string greeting = "Hello There";

    // Skriv ut strengen
    printf("%s\n", greeting);

    // Skriv ut minneadressen til strengen
    printf("%p\n", greeting);

    // Skriv ut minneadressen til det første tegnet i strengen
    printf("%p\n", &greeting[0]);

    // Finner lengden på strengen
    int length = strlen(greeting);

    // Løkke for å iterere gjennom hvert tegn i strengen
    for (int index = 0; index < length; index++)
    {
        // Skriv ut hvert tegn i strengen
        printf("%c\n", greeting[index]);

        // Skriv ut minneadressen til hvert tegn
        printf("%p\n", &greeting[index]);
    }

    return 0;
}
