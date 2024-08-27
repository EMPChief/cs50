#include <stdio.h>

int main(void)
{
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));

    int numbers[] = {1, 2, 3, 4, 5};
    printf("Size of numbers array: %zu bytes\n", sizeof(numbers));
    printf("Number of elements in numbers array: %zu\n", sizeof(numbers) / sizeof(numbers[0]));

    return 0;
}