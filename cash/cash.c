#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Variabel for å holde mengden som skal endres
    int changeOwed;
    // Variabel for å holde brukerens inndata
    char userInput[100];
    // Variabel for å sjekke om inndata er gyldig
    int isValidInput = 0;

    // Spør brukeren om mengden endring tilknyttet og valider inndata
    while (!isValidInput)
    {
        printf("Endring skyldig: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Sjekk om inndata er et gyldig heltall
        if (sscanf(userInput, "%d", &changeOwed) == 1 && changeOwed > 0)
        {
            isValidInput = 1;
        }
        else
        {
            printf("Ugyldig inndata. Vennligst skriv inn et positivt heltall.\n");
        }
    }

    // Variabler for antall mynter
    int numberOfQuarters = 0;
    int numberOfDimes = 0;
    int numberOfNickels = 0;
    int numberOfPennies = 0;

    // Beregn antall kvartaler (25¢)
    while (changeOwed >= 25)
    {
        changeOwed -= 25;
        numberOfQuarters++;
    }

    // Beregn antall ti-cent mynter (10¢)
    while (changeOwed >= 10)
    {
        changeOwed -= 10;
        numberOfDimes++;
    }

    // Beregn antall fem-cent mynter (5¢)
    while (changeOwed >= 5)
    {
        changeOwed -= 5;
        numberOfNickels++;
    }

    // Beregn antall en-cent mynter (1¢)
    while (changeOwed >= 1)
    {
        changeOwed -= 1;
        numberOfPennies++;
    }

    // Beregn totalt antall mynter
    int totalCoins = numberOfQuarters + numberOfDimes + numberOfNickels + numberOfPennies;

    // Skriv ut resultatet
    printf("%d\n", totalCoins);

    return 0;
}
