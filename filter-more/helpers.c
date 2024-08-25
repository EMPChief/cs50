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

// Detect edges
// Detect edges in the image using the Sobel operator
// Denne funksjonen bruker Sobel-operatøren for å detektere kanter i bildet ved å bruke Gx og Gy
// til å beregne gradienter i x- og y-retningene, og deretter kombinerer resultatene for å finne
// kantene.
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    // Sobel operatoren for gradienter i x-retning
    int Gx_array[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    // Sobel operatoren for gradienter i y-retning
    int Gy_array[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int gx_red = 0, gx_green = 0, gx_blue = 0, gy_red = 0, gy_green = 0, gy_blue = 0;
            int counter = 0;
            for (int update_row = row - 1; update_row < row + 2; update_row++)
            {
                for (int update_col = col - 1; update_col < col + 2; update_col++)
                {
                    // Sjekker om piksel er innenfor bildets grenser
                    if (!(update_row < 0 || update_row >= height || update_col < 0 ||
                          update_col >= width))
                    {
                        // Beregn gradientene i x- og y-retningene ved å bruke Sobel operatorene
                        gx_red += Gx_array[counter] * image[update_row][update_col].rgbtRed;
                        gx_green += Gx_array[counter] * image[update_row][update_col].rgbtGreen;
                        gx_blue += Gx_array[counter] * image[update_row][update_col].rgbtBlue;
                        gy_red += Gy_array[counter] * image[update_row][update_col].rgbtRed;
                        gy_green += Gy_array[counter] * image[update_row][update_col].rgbtGreen;
                        gy_blue += Gy_array[counter] * image[update_row][update_col].rgbtBlue;
                    }
                    counter++;
                }
            }

            // Beregn den endelige gradienten ved å kombinere x- og y-gradientene
            int final_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int final_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int final_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            // Begrens verdiene til maksimum 255
            temp_image[row][col].rgbtRed = (final_red > 255) ? 255 : final_red;
            temp_image[row][col].rgbtGreen = (final_green > 255) ? 255 : final_green;
            temp_image[row][col].rgbtBlue = (final_blue > 255) ? 255 : final_blue;
        }
    }

    // Kopierer de detekterte kantene tilbake til det originale bildet
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = temp_image[row][col];
        }
    }
    return;
}
