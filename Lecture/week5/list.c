#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5
#define FINAL_SIZE 10

int main(void)
{
    int *list = malloc(INITIAL_SIZE * sizeof(int));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize all elements
    for (size_t index = 0; index < INITIAL_SIZE; index++)
    {
        list[index] = index;
    }

    // Reallocate memory
    int *tmp_list = realloc(list, FINAL_SIZE * sizeof(int));
    if (tmp_list == NULL)
    {
        fprintf(stderr, "Memory reallocation failed.\n");
        free(list);
        return 2;
    }

    list = tmp_list;

    // Initialize new elements
    for (size_t index = INITIAL_SIZE; index < FINAL_SIZE; index++)
    {
        list[index] = index;
    }

    // Print all elements
    printf("Contents of the array:\n");
    for (size_t index = 0; index < FINAL_SIZE; index++)
    {
        printf("%zu: %d\n", index, list[index]);
    }

    // Free allocated memory
    free(list);

    return 0;
}
