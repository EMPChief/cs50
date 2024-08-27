

#include <stdio.h>
#include <string.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr points to the first element of arr
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *ptr); // Print the value pointed by ptr
        ptr++;               // Move ptr to the next element
    }
}