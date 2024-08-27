#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *first = malloc(80 * sizeof(char));
    char *second = malloc(80 * sizeof(char));
    
    if (first == NULL || second == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("First: ");
    fgets(first, 80, stdin);
    first[strcspn(first, "\n")] = 0;

    printf("Second: ");
    fgets(second, 80, stdin);
    second[strcspn(second, "\n")] = 0;

    printf("Memory address of first: %p\n", first);
    printf("Memory address of second: %p\n", second);

    free(first);
    free(second);
    return 0;
}