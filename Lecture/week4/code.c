#include <stdio.h>

int main(void)
{
    int number = 5;
    int *ptr = &number;
    printf("The address of the variable 'number' is: %p\n", (void*)&number);
    printf("The value of the variable 'number' is: %i\n", *ptr);
    
    return 0;
}



