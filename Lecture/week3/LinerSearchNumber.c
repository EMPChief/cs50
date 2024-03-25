#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

bool linearSearch(int arr[], int size, int target);

int main(void)
{
    int numbers[SIZE] = {10, 20, 30, 40, 50};

    printf("Enter a number to search for: ");
    int numToFind = get_int(NULL);

    bool found = linearSearch(numbers, SIZE, numToFind);
    if (found)
    {
        printf("Number %d found in the array!\n", numToFind);
    }
    else
    {
        printf("Number %d not found in the array.\n", numToFind);
    }

    return 0;
}

bool linearSearch(int arr[], int size, int target)
{
    // This is an example of a linear search
    for (int i = 0; i < size; i++)
    {
        // If we find the number we were looking for, we return true
        if (arr[i] == target)
        {
            return true;
        }
    }
    // We didn't find the number we were looking for, so we return false
    return false;
}
