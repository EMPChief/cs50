#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5
#define FINAL_SIZE 10

int main(void)
{
    // Alloker minne for den opprinnelige listen
    int *list = malloc(INITIAL_SIZE * sizeof(int));
    if (list == NULL)
    {
        fprintf(stderr, "Minneallokering mislyktes.\n");
        return 1;
    }

    // Initialiser alle elementer i den opprinnelige listen
    for (size_t index = 0; index < INITIAL_SIZE; index++)
    {
        list[index] = index;
    }

    // Realloker minne for å utvide listen
    int *tmp_list = realloc(list, FINAL_SIZE * sizeof(int));
    if (tmp_list == NULL)
    {
        fprintf(stderr, "Minnereallokering mislyktes.\n");
        free(list);
        return 2;
    }
    list = tmp_list;

    // Initialiser nye elementer i den utvidede listen
    for (size_t index = INITIAL_SIZE; index < FINAL_SIZE; index++)
    {
        list[index] = index;
    }

    // Skriv ut alle elementer
    printf("Innhold i arrayen:\n");
    for (size_t index = 0; index < FINAL_SIZE; index++)
    {
        printf("%zu: %d\n", index, list[index]);
    }

    // Frigjør allokert minne
    free(list);
    return 0;
}