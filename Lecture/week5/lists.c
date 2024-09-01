#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Alloker minne for 5 heltall
    int *number = malloc(5 * sizeof(int));
    if (number == NULL)
    {
        fprintf(stderr, "Minneallokering mislyktes.\n");
        return 1;
    }

    // Initialiser arrayen med verdier
    number[0] = 1;
    number[1] = 2;
    number[2] = 3;
    number[3] = 4;
    number[4] = 5;

    // Skriv ut den opprinnelige arrayen
    for (int index = 0; index < 5; index++)
    {
        printf("number[%i] = %i\n", index, number[index]);
    }
    printf("--------------------\n");

    // Alloker en ny minneblokk for 10 heltall
    int *tmp = malloc(10 * sizeof(int));
    if (tmp == NULL)
    {
        fprintf(stderr, "Minneallokering mislyktes.\n");
        free(number);
        return 2;
    }

    // Kopier elementene fra den gamle arrayen til den nye
    for (int index = 0; index < 5; index++)
    {
        tmp[index] = number[index];
    }

    // Initialiser de nye elementene
    tmp[5] = 6;
    tmp[6] = 7;
    tmp[7] = 8;
    tmp[8] = 9;
    tmp[9] = 10;

    // Frigjør den gamle minneblokken
    free(number);

    // Tilordne den nye minneblokken til 'number'
    number = tmp;

    // Skriv ut den utvidede arrayen
    for (int index = 0; index < 10; index++)
    {
        printf("number[%i] = %i\n", index, number[index]);
    }

    // Frigjør den nye minneblokken
    free(number);
    return 0;
}