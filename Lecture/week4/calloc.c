#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Alloker minne for 5 heltall og initialiser dem til 0
    int *numbers = calloc(5, sizeof(int));
    if (numbers == NULL)
    {
        fprintf(stderr, "Minneallokering mislyktes\n");
        return 1;
    }

    // Skriv ut verdiene i arrayen
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]); // Vil skrive ut "0 0 0 0 0"
    }
    printf("\n");

    // Frigjør det allokerte minnet
    free(numbers);

    return 0;
}