#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;   // Navn
    string number; // Telefonnummer
} phonebook_entry;

int main(void)
{
    // Telefonkatalog
    phonebook_entry phonebook_array[4];

    phonebook_array[0].name = "Alice";
    phonebook_array[0].number = "123-4567";
    phonebook_array[1].name = "Bob";
    phonebook_array[1].number = "234-5678";
    phonebook_array[2].name = "Charlie";
    phonebook_array[2].number = "345-6789";
    phonebook_array[3].name = "David";
    phonebook_array[3].number = "456-7890";

    // Få brukerens input for navn
    string user_name = get_string("Name: ");

    // Søk etter navnet i telefonkatalogen
    for (int index = 0; index < 4; index++)
    {
        if (strcmp(user_name, phonebook_array[index].name) == 0)
        {
            printf("Number: %s\n", phonebook_array[index].number);
            return 0;
        }
    }

    // Hvis navnet ikke ble funnet
    printf("No such person.\n");
    return 1;
}
