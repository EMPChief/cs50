#include <stdio.h>
#include <string.h>

int main(void)
{
    // Definerer et array med 5 elementer
    int arr[] = {10, 20, 30, 40, 50};

    // Oppretter en peker som peker til det første elementet i arrayet
    int *ptr = arr; // ptr peker til det første elementet i arr

    // Løkke for å iterere gjennom alle elementene i arrayet
    for (int i = 0; i < 5; i++)
    {
        // Skriver ut verdien som ptr peker på
        printf("%d ", *ptr); // Skriv ut verdien som peker peker på

        // Flytter ptr til neste element i arrayet
        ptr++; // Flytt ptr til neste element
    }

    return 0;
}
