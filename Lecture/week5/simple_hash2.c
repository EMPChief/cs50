#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Struktur for en hash-nøkkel
typedef struct HashNode
{
    int key;
    char *value;
    struct HashNode *next;
} HashNode;

// Struktur for hashtabellen
typedef struct
{
    HashNode **buckets;
    int size;
} HashTable;

// Funksjon for å opprette en ny hash-nøkkel
HashNode *create_hash_node(int key, char *value)
{
    HashNode *hash_node = (HashNode *)malloc(sizeof(HashNode));
    hash_node->key = key;
    hash_node->value = value;
    hash_node->next = NULL;
    return hash_node;
}

// Funksjon for å initialisere hashtabellen
HashTable *initialize_hash_table()
{
    HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
    hash_table->size = TABLE_SIZE;
    hash_table->buckets = (HashNode **)calloc(TABLE_SIZE, sizeof(HashNode *));
    return hash_table;
}

// Enkel hash-funksjon: nøkkel % tabellstørrelse
int compute_hash_function(int key)
{
    return key % TABLE_SIZE;
}

// Funksjon for å legge til et nytt nøkkelpar i hashtabellen
void insert_into_hash_table(HashTable *hash_table, int key, char *value)
{
    int bucket_index = compute_hash_function(key);
    HashNode *hash_node = create_hash_node(key, value);

    // Hvis bucket er tom, legg til noden direkte
    if (hash_table->buckets[bucket_index] == NULL)
    {
        hash_table->buckets[bucket_index] = hash_node;
    }
    else
    {
        // Ellers, traverser lenket liste og legg til på slutten
        HashNode *current_node = hash_table->buckets[bucket_index];
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = hash_node;
    }
}

// Funksjon for å søke etter en verdi i hashtabellen
char *search_hash_table(HashTable *hash_table, int key)
{
    int bucket_index = compute_hash_function(key);
    HashNode *current_node = hash_table->buckets[bucket_index];
    while (current_node != NULL && current_node->key != key)
    {
        current_node = current_node->next;
    }
    return current_node ? current_node->value : NULL;
}

// Funksjon for å slette en node fra hashtabellen
void delete_from_hash_table(HashTable *hash_table, int key)
{
    int bucket_index = compute_hash_function(key);
    HashNode **current_node_ptr = &hash_table->buckets[bucket_index];
    while (*current_node_ptr != NULL)
    {
        if ((*current_node_ptr)->key == key)
        {
            HashNode *temp_node = *current_node_ptr;
            *current_node_ptr = (*current_node_ptr)->next;
            free(temp_node);
            break;
        }
        current_node_ptr = &((*current_node_ptr)->next);
    }
}

// Funksjon for å skrive ut innholdet av hashtabellen
void print_hash_table_contents(HashTable *hash_table)
{
    for (int bucket_index = 0; bucket_index < TABLE_SIZE; bucket_index++)
    {
        printf("Bucket %d: ", bucket_index);
        HashNode *current_node = hash_table->buckets[bucket_index];
        if (current_node == NULL)
        {
            printf("TOM\n"); // Endret fra NULL til TOM
        }
        else
        {
            while (current_node != NULL)
            {
                printf("(%d, %s) -> ", current_node->key, current_node->value);
                current_node = current_node->next;
            }
            printf("END\n"); // Endret fra NULL til END
        }
    }
}

int main()
{
    HashTable *hash_table = initialize_hash_table();

    // Legg til noen nøkkelpar
    insert_into_hash_table(hash_table, 10, "Eple");
    insert_into_hash_table(hash_table, 20, "Banan");
    insert_into_hash_table(hash_table, 30, "Kirsebær");
    insert_into_hash_table(hash_table, 40, "Dato");

    // Skriv ut hashtabellen
    printf("Innhold i hashtabellen:\n");
    print_hash_table_contents(hash_table);

    // Søk etter verdier
    printf("\nSøker etter nøkkler:\n");
    int keys_to_search[] = {10, 20, 30, 50}; // Legger til en nøkkel som ikke finnes i tabellen
    int num_keys = sizeof(keys_to_search) / sizeof(keys_to_search[0]);
    for (int index = 0; index < num_keys; index++)
    {
        int key = keys_to_search[index];
        char *result = search_hash_table(hash_table, key);
        if (result != NULL)
        {
            printf("Nøkkel %d funnet: %s\n", key, result);
        }
        else
        {
            printf("Nøkkel %d ikke funnet.\n", key);
        }
    }

    // Slett en node
    delete_from_hash_table(hash_table, 20);

    // Skriv ut den oppdaterte hashtabellen
    printf("\nOppdatert hashtabel etter sletting:\n");
    print_hash_table_contents(hash_table);

    return 0;
}
