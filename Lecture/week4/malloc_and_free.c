#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Allokerer minne for to strenger
    char *first = malloc(80 * sizeof(char));
    char *second = malloc(80 * sizeof(char));

    // Sjekker om minneallokeringen var vellykket
    if (first == NULL || second == NULL)
    {
        printf("Minneallokering mislyktes.\n");
        return 1;
    }

    // Leser inn første streng fra brukeren
    printf("Første: ");
    fgets(first, 80, stdin);
    first[strcspn(first, "\n")] = 0; // Fjerner linjeskift

    // Leser inn andre streng fra brukeren
    printf("Andre: ");
    fgets(second, 80, stdin);
    second[strcspn(second, "\n")] = 0; // Fjerner linjeskift

    // Skriver ut minneadressene til de allokerte strengene
    printf("Minneadresse for første: %p\n", (void *)first);
    printf("Minneadresse for andre: %p\n", (void *)second);

    // Frigjør allokert minne
    free(first);
    free(second);

    return 0;
}