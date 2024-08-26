// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// FUnksjona
unsigned int hash_value;
unsigned int word_count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // ta inn input og skriv et tall til den tilsvarende bøtte
    // gå gjennom listen
    hash_value = hash(word);
    node *cursor = table[hash_value];
    while (cursor != 0)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Gjør hash funksjonen bedre
    unsigned long total = 0;
    for (int index = 0; index < strlen(word); index++)
    {
        total += tolower(word[index]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
// åpne ordboken og returner null, les strenger, opprett en ny node, hash ordet, sett inn node
// fscan hvis slutten av filen nås, while-løkke for å opprette node, malloc av minnestørrelse
// hvis ikke åpnes, NULL
// Opprett en variabel for ord
// skann ordboken for strenger til EOF
// malloc eller returner false, kopier 2 noder
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *cursor = malloc(sizeof(node));
        if (cursor == NULL)
        {
            return false;
        }
        strcpy(cursor->word, word);
        hash_value = hash(word);
        cursor->next = table[hash_value];
        table[hash_value] = cursor;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// retuner ord telling eller retuner 0
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
// lag en temp-variabel som peker til første node
// gjør fri temp-pekeren etter å ha flyttet peker (cursor) og frigjør temp
// frigjør dynamisk allokert minne
bool unload(void)
{
    for (int index = 0; index < N; index++)
    {
        node *cursor = table[index];
        while (cursor != 0)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
