#include <stdio.h>
#include <string.h>

// Definerer en struktur for telefonbok
typedef struct
{
    char name[50];   // Navn, maksimalt 49 tegn + null-terminator
    char number[15]; // Telefonnummer, maksimalt 14 tegn + null-terminator
} phonebook;

int main(void)
{
    // Initialiserer telefonboken med navn og telefonnumre
    phonebook phonebookname[4] = {
        {"Alice", "111-111-1111"},
        {"Bob", "222-222-2222"},
        {"Charlie", "333-333-3333"},
        {"David", "444-444-4444"}};

    // Hent brukerens input for navn
    char name[50];
    printf("Name: ");
    if (fgets(name, sizeof(name), stdin) != NULL)
    {
        // Fjern nyline-tegn fra slutten av input-strengen hvis det er tilstede
        name[strcspn(name, "\n")] = 0;
    }

    // Søk etter navnet i telefonboken
    for (int i = 0; i < 4; i++)
    {
        // Sammenlign brukerens navn med navnene i telefonboken
        if (strcmp(name, phonebookname[i].name) == 0)
        {
            // Hvis navnet finnes, skriv ut telefonnummeret
            printf("Number: %s\n", phonebookname[i].number);
            return 0;
        }
    }

    // Hvis navnet ikke ble funnet, skriv ut en melding
    printf("No such person.\n");
    return 1;
}
