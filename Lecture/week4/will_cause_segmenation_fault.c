#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    // Hent input-streng fra bruker
    char *s = get_string("Før: ");

    // Lag en peker t som peker til samme minneområde som s
    char *t = s;

    // Sjekk at strengen ikke er tom
    if (strlen(t) > 0)
    {
        // Kapitaliser det første tegnet i strengen
        t[0] = toupper(t[0]);
    }

    // Skriv ut resultatet
    printf("Etter: %s\n", t);

    return 0;
}
