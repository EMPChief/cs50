#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if the program was executed with the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key is composed of digits
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a non-negative integer\n");
            return 1;
        }
    }

    // Convert the key from string to an integer
    int key = atoi(argv[1]);

    // Check if the key is non-negative
    if (key < 0)
    {
        printf("Key must be non-negative\n");
        return 1; // Return error code 1 if key is negative
    }

    // Get the plaintext input from the user
    string plaintext = get_string("plaintext: ");

    // Print "ciphertext: " before printing the encrypted text
    printf("ciphertext: ");

    // Iterate through each character of the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // If the character is a lowercase letter
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            // Apply Caesar cipher formula for lowercase letters
            plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
        // If the character is an uppercase letter
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            // Apply Caesar cipher formula for uppercase letters
            plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        }

        // Print the encrypted character
        printf("%c", plaintext[i]);
    }

    // Print a new line after printing all encrypted characters
    printf("\n");

    return 0;
}
