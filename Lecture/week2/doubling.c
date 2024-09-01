#include <stdio.h>
#include "cs50.h"

int main(void)
{
    // Deklarer variabel for størrelsen på arrayet
    int size;

    // Be brukeren om størrelsen på arrayet og valider at inndata er større enn 0 ved hjelp av do-while-løkke
    do
    {
        size = get_int("Skriv inn størrelse på array: ");
    } while (size <= 0);

    // Deklarer et array av heltall med størrelsen gitt av brukeren i do-while-løkken
    int doubling[size];

    // Start en for-løkke for å hente verdier for array-elementer ved hjelp av get_int-funksjonen
    for (int index = 0; index < size; index++)
    {
        // Hent verdier for array-elementer ved hjelp av get_int-funksjonen
        doubling[index] = get_int("Array-element: ");
    }

    // Start en for-løkke for å skrive ut doble verdier av array-elementer ved hjelp av printf-funksjonen og * 2-operatøren
    for (int index = 0; index < size; index++)
    {
        // Skriv ut doble verdier av array-elementer ved hjelp av printf-funksjonen
        printf("%i\n", doubling[index] * 2);
    }

    // Returner 0 for å avslutte programmet med suksessstatuskode (0)
    return 0;
}
