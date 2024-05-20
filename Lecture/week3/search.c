#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int number = get_int("Enter a number: ");
    for (int i = 0; i < 5; i++)
    {
        if (numbers[i] == number)
        {
            printf("Number %d found in the array!\n", number);
            return 0;
        }
    }
    printf("Number %d not found in the array.\n", number);
    return 1;
}