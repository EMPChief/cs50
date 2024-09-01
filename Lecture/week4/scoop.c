#include <stdio.h>

// Globale variabeler er tilgjengelige overalt i filen
int globalVar = 10; // Globalt omfang

// Funksjon som demonstrerer lokal og blokk-spesifikk variabelomfang
void exampleFunction()
{
    // Lokale variabler er bare tilgjengelige innenfor funksjonen de er definert i
    int localVar = 20; // Lokalt omfang
    // Skriver ut den lokale variabelen og den globale variabelen
    printf("Lokal: %d, Global: %d\n", localVar, globalVar);

    {
        // Blokk-spesifikke variabler er kun tilgjengelige innenfor den blokken de er definert i
        int blockVar = 30; // Blokk omfang
        // Skriver ut den blokk-spesifikke variabelen
        printf("Blokk: %d\n", blockVar);
    }
    // blockVar er ikke tilgjengelig her etter blokkens slutt
}

// Hovedfunksjon
int main()
{
    exampleFunction();
    // localVar er ikke tilgjengelig her etter funksjonskallet
    // Skriver ut den globale variabelen
    printf("Global: %d\n", globalVar);
    return 0;
}
