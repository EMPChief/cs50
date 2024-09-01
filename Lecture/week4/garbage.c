#include <stdio.h>

int main(void)
{
    // Deklarerer en array med 2000 heltall
    int scores[2000];

    // Forsøker å skrive ut innholdet i arrayen
    for (int index = 0; index < 2000; index++)
    {
        printf("%i\n", scores[index]);
    }

    return 0;
}