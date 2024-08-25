#include "helpers.h"
#include <math.h>

// Convert image to grayscale
// Få gjennomsnittet av RGB-verdiene og
// sett alle tre til gjennomsnittet - få gjennomsnittet og sett gjennomsnittene
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Går gjennom hver rad i bildet
    for (int row = 0; row < height; row++)
    {
        // Går gjennom hver kolonne i raden
        for (int col = 0; col < width; col++)
        {
            // Få gjennomsnittet av RGB-verdiene for den nåværende pikselen
            int average = round(
                (image[row][col].rgbtBlue + image[row][col].rgbtGreen + image[row][col].rgbtRed) /
                3.0);

            // Sett alle RGB-verdier til gjennomsnittet for å gjøre pikselen gråtonet
            image[row][col].rgbtBlue = average;
            image[row][col].rgbtGreen = average;
            image[row][col].rgbtRed = average;
        }
    }
}

// Convert image to sepia
// Hent den originale RGB-verdien - Sett
// verdien til 'sepia'-versjonen av den originale pikselverdien (fra notatene).
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Går gjennom hver rad i bildet
    for (int row = 0; row < height; row++)
    {
        // Går gjennom hver kolonne i raden
        for (int col = 0; col < width; col++)
        {
            // Deklarerer variabler for å lagre de originale RGB-verdiene
            int originalRed = image[row][col].rgbtRed;
            int originalGreen = image[row][col].rgbtGreen;
            int originalBlue = image[row][col].rgbtBlue;

            // Beregner og setter RGB-verdiene til sepia-versjonen av pikselen
            image[row][col].rgbtRed = fmin(255, (int) (0.393 * originalRed + 0.769 * originalGreen +
                                                       0.189 * originalBlue + 0.5));
            image[row][col].rgbtGreen =
                fmin(255, (int) (0.349 * originalRed + 0.686 * originalGreen +
                                 0.168 * originalBlue + 0.5));
            image[row][col].rgbtBlue =
                fmin(255, (int) (0.272 * originalRed + 0.534 * originalGreen +
                                 0.131 * originalBlue + 0.5));
        }
    }
}

// Reflect image horizontally
// bytt verdiene til piksler fra den andre siden av
// det vertikale senteret av bildet
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Går gjennom hver rad i bildet
    for (int row = 0; row < height; row++)
    {
        // Går gjennom halvparten av kolonnene for å speile bildet horisontalt
        for (int col = 0; col < width / 2; col++)
        {
            // Bytt verdiene til piksler fra den andre siden av det vertikale senteret av bildet
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - 1 - col];
            image[row][width - 1 - col] = temp;
        }
    }
}

// Blur image
// Går over hver piksel - opprett variabler for å lagre RGB-verdier
// og en teller for nærliggende piksler, sett RGB-verdiene til den nåværende pikselen i et
// temp-array til gjennomsnittet av nærliggende piksler. Kopier de uskarpe pikslene fra temp-arrayet
// til det originale bildet
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Oppretter en midlertidig kopi av bildet
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            temp[row][col] = image[row][col];
        }
    }

    // Går over hver piksel i bildet for å beregne gjennomsnittsverdier
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            float counter = 0;

            // Går over nærliggende piksler for å beregne summen av RGB-verdier
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int currentRow = row + i;
                    int currentCol = col + j;

                    // Sjekker om piksel er innenfor bildets grenser
                    if (currentRow < 0 || currentRow >= height || currentCol < 0 ||
                        currentCol >= width)
                    {
                        continue;
                    }

                    // Legger til RGB-verdiene fra den nærliggende pikselen
                    totalRed += image[currentRow][currentCol].rgbtRed;
                    totalGreen += image[currentRow][currentCol].rgbtGreen;
                    totalBlue += image[currentRow][currentCol].rgbtBlue;

                    counter++;
                }
            }

            // Setter gjennomsnittsverdiene i den midlertidige kopien
            temp[row][col].rgbtRed = round(totalRed / counter);
            temp[row][col].rgbtGreen = round(totalGreen / counter);
            temp[row][col].rgbtBlue = round(totalBlue / counter);
        }
    }

    // Kopierer de uskarpe pikslene tilbake til det originale bildet
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = temp[row][col];
        }
    }
}
