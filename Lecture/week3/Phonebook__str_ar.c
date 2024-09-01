#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Telefonbok med navn og telefonnummer
    string phonebookNames[] = {"John Doe", "Jane Doe", "John Smith", "Jane Smith"};
    string phonebookNumbers[] = {"+47-123-456-7890", "+47-123-456-7891", "+47-123-456-7892", "+47-123-456-7893"};

    // Hent brukerens input for navn
    string userName = get_string("Navn: ");

    // Søk etter navnet i telefonboken
    for (int index = 0; index < 4; index++)
    {
        // Sammenlign brukerens navn med navnene i telefonboken
        if (strcmp(userName, phonebookNames[index]) == 0)
        {
            // Hvis navnet finnes, skriv ut telefonnummeret og avslutt med suksess
            printf("Nummer: %s\n", phonebookNumbers[index]);
            return 0;
        }
    }

    // Hvis navnet ikke ble funnet i telefonboken, skriv ut en melding
    printf("Ingen slik person.\n");
    return 1;
}
