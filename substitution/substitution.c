#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// Declare function
bool isValidKey(string key);
char encryptChar(char c, string key);
// Main function
int main(int argc, string argv[])
{
    // Check if key gotten from command line is valid
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // Get the key from the command line and check if it is valid
    string key = argv[1];
    // Check if key is valid or not
    if (!isValidKey(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Get plaintext from user and print ciphertext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    // Declaring length of plaintext to check if it is alphabetic
    int length = strlen(plaintext);
    // Start for loop to check if plaintext is alphabetic
    for (int i = 0; i < length; i++)
    {
        // Check if plaintext is alphabetic or not
        if (isalpha(plaintext[i]))
        {
            printf("%c", encryptChar(plaintext[i], key));
        }
        // If not, print plaintext as it is
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
// Declare function
bool isValidKey(string key)
{
    // Check if key is valid or not
    int keylength = strlen(key);
    // Check if key is 26 characters or not
    if (keylength != 26)
    {
        return false;
    }
    // Check if key is alphabetic or not
    bool marked[26] = {false};
    // Start for loop to check if key is alphabetic
    for (int i = 0; i < keylength; i++)
    {
        // Check if key is alphabetic or not
        if (!isalpha(key[i]))
        {
            return false;
        }
        // Check if key is not used or not
        char c = toupper(key[i]);
        // Check if key is used or not
        if (marked[c - 'A'])
        {
            return false;
        }
        // Mark key as used
        marked[c - 'A'] = true;
    }
    return true;
}
// Declare function
char encryptChar(char c, string key)
{
    // Check if character is alphabetic or not if it is lowercase
    if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    // Check if character is alphabetic or not if it is uppercase
    else if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    return c;
}
