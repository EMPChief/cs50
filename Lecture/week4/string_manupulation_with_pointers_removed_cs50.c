#include <stdio.h>
#include <string.h>

int main(void)
{
    // Initialiserer en peker til en konstant streng med hilsenen
    char *greeting = "Hello There";

    // Skriv ut strengen
    printf("%s\n", greeting);

    // Skriv ut minneadressen til starten av strengen
    printf("%p\n", (void *)greeting);

    // Skriv ut minneadressen til det første tegnet i strengen
    printf("%p\n", (void *)&greeting[0]);

    // Finner lengden på strengen
    int length = strlen(greeting);

    // Løkke for å iterere gjennom hvert tegn i strengen
    for (int index = 0; index < length; index++)
    {
        // Skriv ut hvert tegn i strengen
        printf("%c\n", greeting[index]);

        // Skriv ut minneadressen til hvert tegn i strengen
        printf("%p\n", (void *)&greeting[index]);
    }

    return 0;
}
