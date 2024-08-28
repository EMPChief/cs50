#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

// Function prototypes
void add_entry(const char *filename);
void search_entry(const char *filename);
void lookup_all(const char *filename);
char *toolower(char *str);
void trim_newline(char *str);

int main(void)
{
    // Ask the user what they want to do
    char *user_action = get_string("What do you want to do? (add, search, lookup, exit): ");

    if (user_action == NULL)
    {
        printf("Error: Could not allocate memory for user input.\n");
        return 1;
    }

    const char *filename = "phonebook.csv";

    // Check if the file exists
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        free(user_action);
        return 1;
    }
    fclose(file);

    // Convert user action to lowercase
    user_action = toolower(user_action);

    // Determine action based on user input
    if (strcmp(user_action, "add") == 0)
    {
        add_entry(filename);
    }
    else if (strcmp(user_action, "search") == 0)
    {
        search_entry(filename);
    }
    else if (strcmp(user_action, "lookup") == 0)
    {
        lookup_all(filename);
    }
    else if (strcmp(user_action, "exit") == 0)
    {
        printf("Exiting...\n");
    }
    else
    {
        printf("Unknown command\n");
    }

    // Free allocated memory for user action
    free(user_action);

    return 0;
}

// Function to convert a string to lowercase
char *toolower(char *str)
{
    for (char *ptr = str; *ptr; ++ptr)
    {
        *ptr = tolower((unsigned char)*ptr);
    }
    return str;
}

// Function to remove trailing newline character from a string
void trim_newline(char *str)
{
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
    {
        *pos = '\0';
    }
}

// Function to add a new entry to the phonebook
void add_entry(const char *filename)
{
    // Open the file in append mode
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }

    // Get name and phone number from the user
    char *name = get_string("Enter name: ");
    char *phone_number = get_string("Enter phone number: ");

    if (name == NULL || phone_number == NULL)
    {
        printf("Error: Could not allocate memory for user input.\n");
        fclose(file);
        // Free memory if allocated
        if (name != NULL)
            free(name);
        if (phone_number != NULL)
            free(phone_number);
        return;
    }

    // Write the new entry to the file
    fprintf(file, "%s,%s\n", name, phone_number);

    fclose(file);
    // Free memory after we're done
    free(name);
    free(phone_number);
}

// Function to search for an entry in the phonebook
void search_entry(const char *filename)
{
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s for reading\n", filename);
        return;
    }

    // Get the name to search for from the user
    char *search_name = get_string("Enter name to search: ");
    if (search_name == NULL)
    {
        printf("Error: Could not allocate memory for user input.\n");
        fclose(file);
        return;
    }
    trim_newline(search_name);
    search_name = toolower(search_name);

    char line[256];
    int found = 0;

    // Read through each line in the file
    while (fgets(line, sizeof(line), file))
    {
        // Split the line into name and phone number
        char *name = strtok(line, ",");
        char *phone_number = strtok(NULL, "\n");

        if (name != NULL)
        {
            trim_newline(name);
            name = toolower(name);

            // Check if the name in the file matches the name we're searching for
            if (strcmp(name, search_name) == 0)
            {
                printf("Name: %s, Phone Number: %s\n", name, phone_number);
                found = 1;
                break;
            }
        }
    }

    // Provide feedback to the user if the entry was not found
    if (!found)
    {
        printf("No entry found for %s\n", search_name);
    }

    fclose(file);
    // Free memory after we're done
    free(search_name);
}

// Function to look up all entries in the phonebook
void lookup_all(const char *filename)
{
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s for reading\n", filename);
        return;
    }

    char line[256];

    // Read through each line in the file
    while (fgets(line, sizeof(line), file))
    {
        // Split the line into name and phone number
        char *name = strtok(line, ",");
        char *phone_number = strtok(NULL, "\n");

        // Print the name and phone number to the user
        if (name != NULL && phone_number != NULL)
        {
            trim_newline(name);
            printf("Name: %s, Phone Number: %s\n", name, phone_number);
        }
    }

    fclose(file);
}
