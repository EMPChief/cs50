#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 // Definerer en bufferstørrelse for filoperasjoner

// Funksjonsprototypen for å kopiere filen
void copy_file(const char *source_filename, const char *destination_filename);

int main(void)
{
    const char *source_filename = "phonebook.csv";
    const char *destination_filename = "phone.csv";

    // Kall funksjonen for å kopiere filen
    copy_file(source_filename, destination_filename);

    return 0;
}

// Funksjon for å kopiere en fil fra kilde til destinasjon
void copy_file(const char *source_filename, const char *destination_filename)
{
    // Åpne kildefilen for lesing
    FILE *source_file = fopen(source_filename, "r");
    if (source_file == NULL)
    {
        perror("Feil ved åpning av kildefilen");
        exit(EXIT_FAILURE);
    }

    // Åpne destinasjonsfilen for skriving
    FILE *destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL)
    {
        perror("Feil ved åpning av destinasjonsfilen");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    // Buffer for å lese data
    char buffer[BUFFER_SIZE];

    // Les fra kildefilen og skriv til destinasjonsfilen
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0)
    {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    // Sjekk for lesefeil
    if (ferror(source_file))
    {
        perror("Feil ved lesing fra kildefilen");
    }

    // Lukk filene
    fclose(source_file);
    fclose(destination_file);

    printf("Filen ble kopiert vellykket fra %s til %s\n", source_filename, destination_filename);
}
