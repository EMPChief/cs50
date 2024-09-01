#include <stdio.h>

int main(void)
{
    // Definerer en variabel med navnet 'number' og tilordner den verdien 5
    int number = 5;

    // Skriver ut adressen til variabelen 'number' ved hjelp av %p for å vise pekeren
    printf("Adressen til variabelen 'number' er: %p\n", (void *)&number);

    return 0;
}
