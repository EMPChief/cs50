#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// Declare function
bool isValidKey(string key);
char decryptChar(char c, string key);
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
    // Get ciphertext from user and print plaintext
    string ciphertext = get_string("ciphertext: ");
    printf("plaintext: ");
    // Declaring length of ciphertext to check if it is alphabetic
    int length = strlen(ciphertext);
    // Start for loop to check if ciphertext is alphabetic
    for (int i = 0; i < length; i++)
    {
        // Check if ciphertext is alphabetic or not
        if (isalpha(ciphertext[i]))
        {
            printf("%c", decryptChar(ciphertext[i], key));
        }
        // If not, print ciphertext as it is
        else
        {
            printf("%c", ciphertext[i]);
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
char decryptChar(char c, string key)
{
    // Check if character is alphabetic or not if it is lowercase
    if (islower(c))
    {
        return tolower(key['z' - c]);
    }
    // Check if character is alphabetic or not if it is uppercase
    else if (isupper(c))
    {
        return toupper(key['Z' - c]);
    }
    return c;
}
