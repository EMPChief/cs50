#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(int argument_count, char *argument_values[])
{
    // Sjekk at antall argumenter er korrekt (programnavn + 2 strenger)
    if (argument_count != 3)
    {
        printf("Bruk: ./swap <string> <string>\n");
        return 1;
    }

    // Få lengden av de opprinnelige strengene
    int length_first_string = strlen(argument_values[1]);
    int length_second_string = strlen(argument_values[2]);

    // Bestem maksimal lengde mellom de to strengene
    int max_length = length_first_string > length_second_string ? length_first_string : length_second_string;

    // Lag modifiserbare kopier av strengene med samme lengde som den lengste
    char *first_string = malloc(max_length + 1);
    char *second_string = malloc(max_length + 1);

    // Sjekk at minneallokeringen lykkes
    if (first_string == NULL || second_string == NULL)
    {
        printf("Feil: Minneallokering mislyktes.\n");
        return 1;
    }

    // Kopier de opprinnelige strengene til de nye allokerte minneområdene
    strcpy(first_string, argument_values[1]);
    strcpy(second_string, argument_values[2]);

    // Realloker minne for å sikre at begge strengene er like lange
    first_string = realloc(first_string, max_length + 1);
    second_string = realloc(second_string, max_length + 1);

    // Null-terminer strengene ved den nye lengden hvis nødvendig
    if (length_first_string < max_length)
    {
        memset(first_string + length_first_string, '\0', max_length - length_first_string);
    }
    if (length_second_string < max_length)
    {
        memset(second_string + length_second_string, '\0', max_length - length_second_string);
    }

    // Skriv ut strengene før bytte
    printf("Før: %s %s\n", first_string, second_string);

    // Utfør byttet mellom de to strengene
    for (int index = 0; index < max_length; index++)
    {
        char temp_character = first_string[index];
        first_string[index] = second_string[index];
        second_string[index] = temp_character;
    }

    // Skriv ut strengene etter bytte
    printf("Etter: %s %s\n", first_string, second_string);

    // Frigjør allokert minne
    free(first_string);
    free(second_string);

    return 0;
}
