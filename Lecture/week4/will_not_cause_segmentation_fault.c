#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    // Hent input-streng fra bruker
    char *s = get_string("Før: ");
    
    // Sjekk om minneallokering for input-strengen mislyktes
    if (s == NULL)
    {
        printf("Minneallokering mislyktes.\n");
        return 1;
    }
    
    // Alloker minne for en kopi av strengen
    char *t = malloc(strlen(s) + 1);  // +1 for null-terminator
    
    // Sjekk om minneallokering for den nye strengen mislyktes
    if (t == NULL)
    {
        printf("Minneallokering mislyktes.\n");
        free(s);  // Frigjør minnet for input-strengen før vi avslutter
        return 2;
    }

    // Kopier strengen fra s til t
    strcpy(t, s);
    
    // Kapitaliser det første tegnet i strengen t hvis den ikke er tom
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    
    // Skriv ut resultatet
    printf("Etter: %s\n", t);
    
    // Frigjør minnet som ble allokert for strengen t
    free(t);
    
    // Frigjør minnet som ble allokert for strengen s
    free(s);
    
    return 0;
}
