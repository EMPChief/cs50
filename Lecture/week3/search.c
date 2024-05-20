#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string stringlist[] = {"apple", "banana", "cherry", "date", "elderberry"};

    string search = get_string("Search: ");
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(stringlist[i], search) == 0)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}
