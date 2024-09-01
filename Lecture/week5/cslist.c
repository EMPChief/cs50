#include <stdio.h>
#include <stdlib.h>

// Definerer en struktur for en node i den lenkede listen
typedef struct node
{
    int data;          // Data som lagres i noden
    struct node *next; // Pekeren til neste node
} node;

int main(int argc, char *argv[])
{
    // Kontrollerer at det er tilstrekkelig antall kommandolinjeargumenter
    if (argc < 2)
    {
        printf("Usage: ./cslist <data>\n");
        return 1;
    }

    node *list = NULL;
    node *last = NULL; // Pekeren til den siste noden i listen

    // Går gjennom alle kommandolinjeargumentene og lager noder
    for (int index = 1; index < argc; index++)
    {
        // Konverterer kommandolinjeargumentet til et heltall
        int number = atoi(argv[index]);

        // Allokerer minne for en ny node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            return 2;
        }

        // Setter verdiene i den nye noden
        new_node->data = number;
        new_node->next = NULL; // Ny node er nå den siste

        if (list == NULL)
        {
            // Hvis listen er tom, blir den nye noden den første noden
            list = new_node;
        }
        else
        {
            // Ellers, legg den nye noden til slutten av listen
            last->next = new_node;
        }

        // Oppdater last til å være den nye noden
        last = new_node;

        // Debug: Print the value added to the list
        printf("Added node with value: %d\n", number);
    }

    // Skriver ut innholdet i den lenkede listen
    node *cursor = list;
    while (cursor != NULL)
    {
        printf("%i\n", cursor->data);
        cursor = cursor->next;
    }

    // Frigjør minne for hver node i listen
    node *tmp;
    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }

    return 0;
}
