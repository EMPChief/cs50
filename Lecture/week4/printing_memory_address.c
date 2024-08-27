#include <stdio.h>

int main(void)
{
    int number = 5;
    printf("The address of the variable 'number' is: %p\n", (void*)&number);
    return 0;
}