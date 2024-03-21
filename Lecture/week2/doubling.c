
#include <stdio.h>
#include "cs50.h"

int main(void)
{
    // Declare variables
    int size;
    // Prompt user for size of array and validate input is greater than 0 using do while loop
    do
    {
        size = get_int("Enter size of array: ");
    }while(size <= 0);
    // Declare array of integers with size given by user in do while loop
    int doubling[size];
    // Start for loop to get values for array elements using get_int function
    for(int i = 0; i < size; i++)
    {
        // Get values for array elements using get_int function and validate input is greater than 0
        doubling[i] = get_int("Array element: ");
    }
    // Start for loop to print doubled values of array elements using printf function and * 2 operator
    for(int i = 0; i < size; i++)
    {
        // Print doubled values of array elements using printf function
        printf("%i\n", doubling[i] * 2);
    }
    // Return 0 to end program with success status code (0)
    return 0;
}
