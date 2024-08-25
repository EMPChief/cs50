#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // Sjekk for korrekt bruk
    if (argc != 2)
    {
        // Skriv ut feilmelding hvis programmet ikke får det korrekte antallet kommandolinjeargumenter
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Åpne det rettsmedisinske bildefilen spesifisert på kommandolinjeargumentet
    char *input_filename = argv[1];
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        // Skriv ut feilmelding hvis det rettsmedisinske bildefilen ikke kan åpnes
        printf("Could not open file.\n");
        return 1;
    }

    // Initialiser variabler
    bool is_jpeg_open = false;            // Flagg for å holde oversikt over om bildet er en JPEG
    int jpeg_file_count = 0;              // Teller for å holde oversikt over antall JPEG-bilder i bildet
    uint8_t file_buffer[MAX_BUFFER_SIZE]; // Puffer for å lagre JPEG-bildedata som finnes
    char jpeg_filename[8];                // Array for å lagre JPEG-filnavnene
    FILE *jpeg_file = NULL;               // Pekeren til den nåværende JPEG-filen

    size_t bytes_read; // Variable to store the number of bytes read

    // Les rettsmedisinske bildefilen blokk for blokk
    while ((bytes_read = fread(file_buffer, 1, MAX_BUFFER_SIZE, input_file)) > 0)
    {
        // Sjekk om denne blokken markerer starten på et JPEG-bilde
        if (file_buffer[0] == 0xff && file_buffer[1] == 0xd8 && file_buffer[2] == 0xff && (file_buffer[3] & 0xf0) == 0xe0)
        {
            // Hvis ja, lukk det nåværende JPEG-bildet hvis det er åpent
            if (is_jpeg_open)
            {
                fclose(jpeg_file);
            }

            // Åpne en ny JPEG-fil
            sprintf(jpeg_filename, "%03i.jpg", jpeg_file_count); // Generer filnavnet for JPEG-bildet basert på variabelen jpeg_file_count
            jpeg_file = fopen(jpeg_filename, "w");               // Åpne den nye JPEG-filen
            if (jpeg_file == NULL)
            {
                // Skriv ut feilmelding hvis JPEG-filen ikke kan opprettes
                printf("Could not create %s.\n", jpeg_filename);
                fclose(input_file);
                return 3;
            }

            jpeg_file_count++; // Øk variabelen jpeg_file_count
            is_jpeg_open = true;
        }

        // Skriv den nåværende blokken til den nåværende JPEG-filen hvis en er åpen
        if (is_jpeg_open)
        {
            fwrite(file_buffer, 1, bytes_read, jpeg_file);
        }
    }

    // Lukk den rettsmedisinske bildefilen og den siste JPEG-filen hvis en er åpen
    fclose(input_file);
    if (is_jpeg_open)
    {
        fclose(jpeg_file);
    }

    // Avslutt programmet med statuskode 0 (suksess) hvis ingen feil ble oppdaget
    return 0;
}
