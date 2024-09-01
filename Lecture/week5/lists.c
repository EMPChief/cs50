#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *number = malloc(5 * sizeof(int));
    if (number == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    number[0] = 1;
    number[1] = 2;
    number[2] = 3;
    number[3] = 4;
    number[4] = 5;

    for (int index = 0; index < 5; index++)
    {
        printf("number[%i] = %i\n", index, number[index]);
    }
    printf("--------------------\n");

    // Allocate a new block of memory for 10 integers
    int *tmp = malloc(10 * sizeof(int));
    if (tmp == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        free(number);
        return 2;
    }

    // Copy the elements from the old array to the new one
    for (int index = 0; index < 5; index++)
    {
        tmp[index] = number[index];
    }

    // Initialize the new elements
    tmp[5] = 6;
    tmp[6] = 7;
    tmp[7] = 8;
    tmp[8] = 9;
    tmp[9] = 10;

    // Free the old memory block
    free(number);

    // Assign the new block of memory to `number`
    number = tmp;

    // Print the expanded array
    for (int index = 0; index < 10; index++)
    {
        printf("number[%i] = %i\n", index, number[index]);
    }

    // Free the new memory block
    free(number);

    return 0;
}
