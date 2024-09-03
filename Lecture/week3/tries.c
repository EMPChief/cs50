#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Strukturdefinisjon for en node i trie
// Hver node kan ha opptil 26 barn (ett for hver bokstav i alfabetet)
// og et flagg som indikerer om det er slutten på et gyldig ord
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE]; // Array med pekere til barnenoder
    int is_end_of_word;                       // Flagg for å markere slutten på et ord
} TrieNode;

// Funksjon for å opprette en ny node i trie
// Allokerer minne for en ny node, initialiserer alle barn til NULL,
// og setter flagget for slutten på ord til 0 (false)
TrieNode *create_trie_node()
{
    TrieNode *new_node = (TrieNode *)malloc(sizeof(TrieNode));
    new_node->is_end_of_word = 0; // Dette er ikke slutten på et ord ennå
    for (int alphabet_index = 0; alphabet_index < ALPHABET_SIZE; alphabet_index++)
    {
        new_node->children[alphabet_index] = NULL; // Alle barn settes til NULL
    }
    return new_node;
}

// Funksjon for å sette inn et ord i trie
// Itererer over hver bokstav i ordet, traverserer eller oppretter noder etter behov
void insert_into_trie(TrieNode *root_node, const char *word)
{
    TrieNode *current_node = root_node;

    for (int character_index = 0; character_index < strlen(word); character_index++)
    {
        // Beregner posisjonen i alfabetet for den nåværende bokstaven
        int alphabet_position = word[character_index] - 'a';

        // Hvis den aktuelle barnenoden ikke eksisterer, opprett en ny node
        if (current_node->children[alphabet_position] == NULL)
        {
            current_node->children[alphabet_position] = create_trie_node();
        }
        // Gå videre til neste node
        current_node = current_node->children[alphabet_position];
    }

    // Marker slutten på ordet
    current_node->is_end_of_word = 1;
}

// Funksjon for å søke etter et ord i trie
// Traverserer trie basert på bokstavene i ordet, og sjekker om det er et gyldig ord
int search_in_trie(TrieNode *root_node, const char *word)
{
    TrieNode *current_node = root_node;

    // Gå gjennom hver bokstav i ordet
    for (int character_index = 0; character_index < strlen(word); character_index++)
    {
        // Beregner posisjonen i alfabetet for den nåværende bokstaven
        int alphabet_position = word[character_index] - 'a';

        // Hvis det ikke finnes en barnenode for den nåværende bokstaven, er ordet ikke i trie
        if (current_node->children[alphabet_position] == NULL)
        {
            return 0; // Ordet ble ikke funnet
        }
        // Gå videre til neste node
        current_node = current_node->children[alphabet_position];
    }

    // Returner true hvis vi er på slutten av et gyldig ord, ellers false
    return (current_node != NULL && current_node->is_end_of_word);
}

// Funksjon for å vise innholdet i trie (rekursiv funksjon)
// Traverserer alle nodene i trie og skriver ut hvert gyldig ord
void display_trie(TrieNode *root_node, char *prefix, int length)
{
    // Hvis noden markerer slutten på et ord, skriv ut ordet
    if (root_node->is_end_of_word)
    {
        prefix[length] = '\0';
        printf("%s\n", prefix);
    }

    // Gå gjennom alle barnenodene
    for (int alphabet_index = 0; alphabet_index < ALPHABET_SIZE; alphabet_index++)
    {
        if (root_node->children[alphabet_index] != NULL)
        {
            // Legg til den nåværende bokstaven i prefixet og traverser videre
            prefix[length] = alphabet_index + 'a';
            display_trie(root_node->children[alphabet_index], prefix, length + 1);
        }
    }
}

int main()
{
    // Opprett roten av trie
    TrieNode *root_node = create_trie_node();

    // Liste over ord som skal settes inn i trie
    char *words[] = {"eple", "banan", "druer", "druedrikk", "appelsin"};
    int number_of_words = sizeof(words) / sizeof(words[0]);

    // Sett inn ordene i trie
    for (int word_index = 0; word_index < number_of_words; word_index++)
    {
        insert_into_trie(root_node, words[word_index]);
    }

    // Søk etter noen ord i trie
    printf("Søker etter ord i trie:\n");
    char *words_to_search[] = {"eple", "druer", "pære", "druedrikk"};
    int number_of_search_words = sizeof(words_to_search) / sizeof(words_to_search[0]);

    for (int search_index = 0; search_index < number_of_search_words; search_index++)
    {
        printf("%s: %s\n", words_to_search[search_index],
               search_in_trie(root_node, words_to_search[search_index]) ? "Funnet" : "Ikke funnet");
    }

    // Vis innholdet i trie
    printf("\nInnholdet i trie:\n");
    char prefix[100];
    display_trie(root_node, prefix, 0);

    return 0;
}
