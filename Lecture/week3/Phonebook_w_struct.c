#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Definerer en struktur for telefonbok
typedef struct
{
    string name;   // Navn
    string number; // Telefonnummer
} phonebook;

int main(void)
{
    // Initialiserer telefonboken med navn og telefonnumre
    phonebook phonebookEntries[4] = {
        {"Alice", "111-111-1111"},
        {"Bob", "222-222-2222"},
        {"Charlie", "333-333-3333"},
        {"David", "444-444-4444"}};

    // Hent brukerens input for navn
    string userName = get_string("Navn: ");

    // Søk etter navnet i telefonboken
    for (int index = 0; index < 4; index++)
    {
        // Sammenlign brukerens navn med navnene i telefonboken
        if (strcmp(userName, phonebookEntries[index].name) == 0)
        {
            // Hvis navnet finnes, skriv ut telefonnummeret og avslutt med suksess
            printf("Nummer: %s\n", phonebookEntries[index].number);
            return 0;
        }
    }

    // Hvis navnet ikke ble funnet i telefonboken, skriv ut en melding
    printf("Ingen slik person.\n");
    return 1;
}
