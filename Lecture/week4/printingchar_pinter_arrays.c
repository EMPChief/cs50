#include <stdio.h>
#include <string.h>

int main(void)
{
    char *greeting = "Hello There";
    printf("%c\n", *greeting);
    printf("%c\n", *(greeting + 1));
    printf("%c\n", *(greeting + 2));
    printf("%c\n", *(greeting + 3));
    printf("%c\n", *(greeting + 4));
    int length = strlen(greeting);
    for (int index = 0; index < length; index++)
    {
        printf("%c\n", *(greeting + index));
    }
    return 0;
}