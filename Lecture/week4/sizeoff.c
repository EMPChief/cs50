#include <stdio.h>

int main(void)
{
    // Skriver ut størrelsen på forskjellige datatyper i byte
    printf("Størrelse av int: %zu bytes\n", sizeof(int));       // Størrelsen på en int
    printf("Størrelse av char: %zu byte\n", sizeof(char));      // Størrelsen på en char
    printf("Størrelse av float: %zu bytes\n", sizeof(float));   // Størrelsen på en float
    printf("Størrelse av double: %zu bytes\n", sizeof(double)); // Størrelsen på en double

    // Definerer et array med 5 heltall
    int numbers[] = {1, 2, 3, 4, 5};

    // Skriver ut størrelsen på hele arrayet i byte
    printf("Størrelse av numbers-arrayet: %zu bytes\n", sizeof(numbers));
    // Beregner og skriver ut antall elementer i arrayet
    printf("Antall elementer i numbers-arrayet: %zu\n", sizeof(numbers) / sizeof(numbers[0]));

    return 0;
}
