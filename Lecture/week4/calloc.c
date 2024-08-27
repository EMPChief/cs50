#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numbers = calloc(5, sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);  // Will print "0 0 0 0 0"
    }
    printf("\n");

    free(numbers);
    return 0;
}