## Example Code: Linear Search Algorithm with int array
```c
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
```
### Example Code: Linear Search Algorithm with string array
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string stringlist[] = {"apple", "banana", "cherry", "date", "elderberry"};

    string search = get_string("Search: ");
    for (int i = 0; i < 5; i++)
    {
        // strcmp() returns 0 if the strings are equal and -1 if the first string is less than the second. 
        if (strcmp(stringlist[i], search) == 0)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}
```
### Example Code: Phonebook with string array
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Phonebook
    string phonebookname[] = {"John Doe", "Jane Doe", "John Smith", "Jane Smith"};
    string phonebooknumber[] = {"+47-123-456-7890", "+47-123-456-7891", "+47-123-456-7892", "+47-123-456-7893"};

    // Get user's input for name
    string name = get_string("Name: ");
    
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, phonebookname[i]) == 0)
        {
            printf("Number: %s\n", phonebooknumber[i]);
            return 0;
        }
    }
    printf("No such person.\n");

    return 1;
}
```
### Example Code: Phonebook with struct array 
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
    phonebook phonebookname[4] = {
        {"Alice", "111-111-1111"},
        {"Bob", "222-222-2222"},
        {"Charlie", "333-333-3333"},
        {"David", "444-444-4444"}
    };

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
### Example Code: Phonebook with struct array with typedef
```c
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char number[15];
} phonebook;

int main(void)
{
    // Phonebook
    phonebook phonebookname[4] = {
        {"Alice", "111-111-1111"},
        {"Bob", "222-222-2222"},
        {"Charlie", "333-333-3333"},
        {"David", "444-444-4444"}
    };

    // Get user's input for name
    char name[50];
    printf("Name: ");
    if (fgets(name, sizeof(name), stdin) != NULL)
    {
        // Remove newline character from the end of the input if present
        name[strcspn(name, "\n")] = 0;
    }

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