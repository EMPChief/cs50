#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Initialiserer en liste med strenger
    string stringList[] = {"apple", "banana", "cherry", "date", "elderberry"};

    // Få søkestrengen fra brukeren
    string searchString = get_string("Søk etter: ");

    // Gå gjennom hver streng i listen
    for (int index = 0; index < 5; index++)
    {
        // strcmp() returnerer 0 hvis strengene er like
        if (strcmp(stringList[index], searchString) == 0)
        {
            // Hvis strengen ble funnet, skriv ut melding og avslutt programmet med suksesskode
            printf("Funnet!\n");
            return 0;
        }
    }

    // Hvis strengen ikke ble funnet i listen, skriv ut melding og avslutt med feilkode
    printf("Ikke funnet.\n");
    return 1;
}
