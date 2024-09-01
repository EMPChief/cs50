
### Example Code: Phonebook with struct array with typedef
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} phonebook;

int main(void)
{
    // Phonebook
    phonebook phonebookname[4];

    phonebookname[0].name = "Alice";
    phonebookname[0].number = "123-4567";
    phonebookname[1].name = "Bob";
    phonebookname[1].number = "234-5678";
    phonebookname[2].name = "Charlie";
    phonebookname[2].number = "345-6789";
    phonebookname[3].name = "David";
    phonebookname[3].number = "456-7890";

    // Get user's input for name
    string name = get_string("Name: ");

    // Search for the name in the phonebook
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, phonebookname[i].name) == 0)
        {
            printf("Number: %s\n", phonebookname[i].number);
            return 0;
        }
    }

    // If the name was not found
    printf("No such person.\n");
    return 1;
}
```