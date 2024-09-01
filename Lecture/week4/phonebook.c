#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

// Funksjonsprototyper
void add_entry(const char *filename);
void search_entry(const char *filename);
void lookup_all(const char *filename);
char *toolower(char *str);
void trim_newline(char *str);

int main(void)
{
    // Spør brukeren hva de vil gjøre
    char *user_action = get_string("Hva vil du gjøre? (legg til, søk, vis, avslutt): ");

    if (user_action == NULL)
    {
        printf("Feil: Kunne ikke allokere minne for brukerens input.\n");
        return 1;
    }

    const char *filename = "phonebook.csv";

    // Sjekker om filen eksisterer
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Feil: Kunne ikke åpne filen %s\n", filename);
        free(user_action);
        return 1;
    }
    fclose(file);

    // Konverterer brukerens handling til små bokstaver
    user_action = toolower(user_action);

    // Bestemmer handling basert på brukerens input
    if (strcmp(user_action, "legg til") == 0)
    {
        add_entry(filename);
    }
    else if (strcmp(user_action, "søk") == 0)
    {
        search_entry(filename);
    }
    else if (strcmp(user_action, "vis") == 0)
    {
        lookup_all(filename);
    }
    else if (strcmp(user_action, "avslutt") == 0)
    {
        printf("Avslutter...\n");
    }
    else
    {
        printf("Ukjent kommando\n");
    }

    // Frigjør allokert minne for brukerens handling
    free(user_action);

    return 0;
}

// Funksjon for å konvertere en streng til små bokstaver
char *toolower(char *str)
{
    for (char *ptr = str; *ptr; ++ptr)
    {
        *ptr = tolower((unsigned char)*ptr);
    }
    return str;
}

// Funksjon for å fjerne den avsluttende linjeskiftkarakteren fra en streng
void trim_newline(char *str)
{
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
    {
        *pos = '\0';
    }
}

// Funksjon for å legge til en ny oppføring i telefonboken
void add_entry(const char *filename)
{
    // Åpner filen i tillegg-modus
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Feil: Kunne ikke åpne filen %s for skriving\n", filename);
        return;
    }

    // Få navn og telefonnummer fra brukeren
    char *name = get_string("Skriv inn navn: ");
    char *phone_number = get_string("Skriv inn telefonnummer: ");

    if (name == NULL || phone_number == NULL)
    {
        printf("Feil: Kunne ikke allokere minne for brukerens input.\n");
        fclose(file);
        // Frigjør minne hvis allokert
        if (name != NULL)
            free(name);
        if (phone_number != NULL)
            free(phone_number);
        return;
    }

    // Skriv den nye oppføringen til filen
    fprintf(file, "%s,%s\n", name, phone_number);

    fclose(file);
    // Frigjør minne etter at vi er ferdige
    free(name);
    free(phone_number);
}

// Funksjon for å søke etter en oppføring i telefonboken
void search_entry(const char *filename)
{
    // Åpner filen i lesemodus
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Feil: Kunne ikke åpne filen %s for lesing\n", filename);
        return;
    }

    // Få navnet å søke etter fra brukeren
    char *search_name = get_string("Skriv inn navn å søke etter: ");
    if (search_name == NULL)
    {
        printf("Feil: Kunne ikke allokere minne for brukerens input.\n");
        fclose(file);
        return;
    }
    trim_newline(search_name);
    search_name = toolower(search_name);

    char line[256];
    int found = 0;

    // Leser gjennom hver linje i filen
    while (fgets(line, sizeof(line), file))
    {
        // Deler linjen inn i navn og telefonnummer
        char *name = strtok(line, ",");
        char *phone_number = strtok(NULL, "\n");

        if (name != NULL)
        {
            trim_newline(name);
            name = toolower(name);

            // Sjekk om navnet i filen samsvarer med navnet vi søker etter
            if (strcmp(name, search_name) == 0)
            {
                printf("Navn: %s, Telefonnummer: %s\n", name, phone_number);
                found = 1;
                break;
            }
        }
    }

    // Gi tilbakemelding til brukeren hvis oppføringen ikke ble funnet
    if (!found)
    {
        printf("Ingen oppføring funnet for %s\n", search_name);
    }

    fclose(file);
    // Frigjør minne etter at vi er ferdige
    free(search_name);
}

// Funksjon for å vise alle oppføringer i telefonboken
void lookup_all(const char *filename)
{
    // Åpner filen i lesemodus
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Feil: Kunne ikke åpne filen %s for lesing\n", filename);
        return;
    }

    char line[256];

    // Leser gjennom hver linje i filen
    while (fgets(line, sizeof(line), file))
    {
        // Deler linjen inn i navn og telefonnummer
        char *name = strtok(line, ",");
        char *phone_number = strtok(NULL, "\n");

        // Skriv ut navn og telefonnummer til brukeren
        if (name != NULL && phone_number != NULL)
        {
            trim_newline(name);
            printf("Navn: %s, Telefonnummer: %s\n", name, phone_number);
        }
    }

    fclose(file);
}
