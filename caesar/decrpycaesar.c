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

    // Get the ciphertext input from the user
    string ciphertext = get_string("ciphertext: ");

    // Print "plaintext: " before printing the decrypted text
    printf("plaintext: ");

    // Iterate through each character of the ciphertext
    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        // If the character is a lowercase letter
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
        {
            // Apply Caesar cipher formula for lowercase letters 
            ciphertext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        }
        // If the character is an uppercase letter
        else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
        {
            // Apply Caesar cipher formula for uppercase letters
            ciphertext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        }

        // Print the decrypted character
        printf("%c", ciphertext[i]);
    }

    // Print a new line after printing all decrypted characters
    printf("\n");

    return 0;
}
