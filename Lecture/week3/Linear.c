#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialiserer en array med fem heltall
    int numbers[5] = {10, 20, 30, 40, 50};

    // Få et tall fra brukeren
    int userNumber = get_int("Skriv inn et tall: ");

    // Sjekk hvert element i arrayen
    for (int index = 0; index < 5; index++)
    {
        // Hvis tallet fra brukeren finnes i arrayen
        if (numbers[index] == userNumber)
        {
            // Skriv ut melding om at tallet er funnet
            printf("Tallet %d ble funnet i arrayen!\n", userNumber);
            return 0; // Avslutt programmet med suksesskode
        }
    }

    // Hvis tallet ikke ble funnet i arrayen
    printf("Tallet %d ble ikke funnet i arrayen.\n", userNumber);
    return 1; // Avslutt programmet med feilkode
}
