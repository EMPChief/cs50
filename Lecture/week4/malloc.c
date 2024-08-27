#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *hello = malloc(6 * sizeof(char));  // Allocate space for 5 chars + null terminator
    if (hello == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    hello[0] = 'H';
    hello[1] = 'e';
    hello[2] = 'l';
    hello[3] = 'l';
    hello[4] = 'o';
    hello[5] = '\0';  // Null terminator

    printf("%s\n", hello);
    free(hello);
    return 0;
}