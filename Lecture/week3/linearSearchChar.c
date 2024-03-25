#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool linearSearch(const char *str);

int main(void)
{
    char input[100]; // Maximum input size assumed to be 100 characters

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character if present

    bool found = linearSearch(input);
    if (found)
    {
        printf("Character 'o' found in the string!\n");
    }
    else
    {
        printf("Character 'o' not found in the string.\n");
    }

    return 0;
}

bool linearSearch(const char *str)
{
    char target = 'o';
    // This is an example of a linear search
    for (int i = 0; i < strlen(str); i++)
    {
        // If we find the character we were looking for, we return true
        if (str[i] == target)
        {
            return true;
        }
    }
    // We didn't find the character we were looking for, so we return false
    return false;
}
