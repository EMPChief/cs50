#include <stdio.h>

int main(void)
{
    // Deklarerer en heltallsvariabel og en peker
    int number = 5;
    int *ptr = &number;

    // Skriver ut adressen til variabelen 'number'
    printf("Adressen til variabelen 'number' er: %p\n", (void *)&number);

    // Skriver ut verdien av 'number' ved å dereferere pekeren
    printf("Verdien av variabelen 'number' er: %i\n", *ptr);

    // Skriver ut verdien av 'number' direkte
    printf("Verdien av variabelen 'number' er: %i\n", number);

    // Endrer verdien av 'number' ved å bruke pekeren
    *ptr = 10;

    // Skriver ut den nye verdien av 'number' ved å dereferere pekeren
    printf("Verdien av variabelen 'number' er nå: %i\n", *ptr);

    // Skriver ut den nye verdien av 'number' direkte
    printf("Verdien av variabelen 'number' er nå: %i\n", number);

    return 0;
}