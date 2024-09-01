#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    // Hent brukerens navn
    string name = get_string("Hva er navnet ditt? ");

    // Hent lengden av navnet
    int length = strlen(name);

    // Skriv ut lengden
    printf("Lengde: %i\n", length);

    return 0;
}
