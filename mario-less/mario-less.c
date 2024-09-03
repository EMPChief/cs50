#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int height;
    char input[10];

    // Be brukeren om høyden på pyramiden (1-8)
    do
    {
        printf("Skriv inn høyden på pyramiden (1-8): ");
        fgets(input, sizeof(input), stdin);
    }
    while (sscanf(input, "%d", &height) != 1 || height < 1 || height > 8);

    // Gå gjennom hver rad for å bygge pyramiden
    for (int currentRow = 1; currentRow <= height; currentRow++)
    {
        // Skriv ut mellomrom før venstre hash-tegn
        int spacesBeforeHashes = height - currentRow;
        for (int currentSpace = 0; currentSpace < spacesBeforeHashes; currentSpace++)
        {
            printf(" ");
        }

        // Skriv ut venstre hash-tegn
        int numberOfHashes = currentRow;
        for (int currentHash = 0; currentHash < numberOfHashes; currentHash++)
        {
            printf("#");
        }

        // Gå til neste linje for neste rad
        printf("\n");
    }

    return 0;
}
