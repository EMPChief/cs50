#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allokerer plass for 3 heltall (int)
    int *x = malloc(3 * sizeof(int));

    // Sjekker om minneallokeringen mislyktes
    if (x == NULL)
    {
        return 1; // Returnerer en feilkode hvis allokeringen feilet
    }

    // Tildeler verdier til de allokerte minneplassene
    x[0] = 50;
    x[1] = 72;
    x[2] = 101;

    // Frigjør det allokerte minnet
    free(x);

    return 0; // Returnerer 0 for å indikere at programmet avsluttet vellykket
}
