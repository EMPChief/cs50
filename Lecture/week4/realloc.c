#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *hello = malloc(6 * sizeof(char));
    if (hello == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(hello, "Hello");
    printf("%s\n", hello);

    hello = realloc(hello, 11 * sizeof(char));
    if (hello == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    strcat(hello, " World");
    printf("%s\n", hello);

    free(hello);
    return 0;
}