#include <stdio.h>
#include "cs50.h"

// Hovedfunksjon med argumenter for kommandolinjen
int main(int argc, string argv[])
{
    // Start en for-løkke for å skrive ut "Hello" til hver kommandolinje-parameter
    for (int i = 1; i < argc; i++)
    {
        printf("Hello, %s\n", argv[i]);
    }

    // Skriver ut en tom linje for å skille utdataene
    printf("\n");

    // Skriver ut ASCII-tegning av et ansikt
    printf("        *****        \n");
    printf("    ***       ***    \n");
    printf("  **             **  \n");
    printf(" **   \\  O O  /   ** \n");
    printf("**     \\  ^  /     **\n");
    printf("**     |     |     **\n");
    printf("**     |     |     **\n");
    printf(" **    \\___/    **  \n");
    printf("  **           **   \n");
    printf("    ***     ***     \n");
    printf("        *****       \n");

    // Skriver ut en tom linje for å avslutte utdataene pent
    printf("\n");

    // Returner 0 for å avslutte programmet med suksessstatuskode (0)
    return 0;
}
