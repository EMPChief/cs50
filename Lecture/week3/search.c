#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Funksjonsprototyp for å tegne pyramiden
void draw(int height);

int main(void)
{
    // Hent høyden på pyramiden fra brukeren
    int height = get_int("Høyde: ");
    // Tegn pyramiden med den angitte høyden
    draw(height);
}

// Funksjon for å tegne pyramiden
void draw(int height)
{
    int row, column;
    // Gå gjennom hver rad i pyramiden
    for (row = 0; row < height; row++)
    {
        // Gå gjennom hver kolonne i raden
        for (column = 0; column < height; column++)
        {
            // Skriv ut et mellomrom hvis kolonnen er før den delen som skal være en '#'
            if (column < height - row - 1)
            {
                printf(" ");
            }
            else
            {
                // Ellers, skriv ut en '#'
                printf("#");
            }
        }
        // Gå til neste rad etter å ha skrevet ut en rad
        printf("\n");
    }
}
