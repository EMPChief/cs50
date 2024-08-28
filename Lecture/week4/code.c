#include <stdio.h>

int main(void)
{
    int number = 5;
    int *ptr = &number;
    printf("The address of the variable 'number' is: %p\n", (void*)&number);
    printf("The value of the variable 'number' is: %i\n", *ptr);
    printf("The value of the variable 'number' is: %i\n", number);

    *ptr = 10;
    printf("The value of the variable 'number' is: %i\n", *ptr);
    printf("The value of the variable 'number' is: %i\n", number);
    
    return 0;
}



