#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allokerer plass for 5 tegn + null-terminator
    char *hello = malloc(6 * sizeof(char));
    if (hello == NULL)
    {
        // Sjekker om minneallokeringen feilet
        fprintf(stderr, "Minneallokering mislyktes\n");
        return 1; // Returnerer en feilkode
    }

    // Setter tegnene i strengen "Hello"
    hello[0] = 'H';
    hello[1] = 'e';
    hello[2] = 'l';
    hello[3] = 'l';
    hello[4] = 'o';
    hello[5] = '\0'; // Null-terminator

    // Skriver ut strengen
    printf("%s\n", hello);

    // Frigjør det allokerte minnet
    free(hello);

    return 0; // Returnerer 0 for å indikere at programmet avsluttet vellykket
}
