#include <stdio.h>
#include <stdlib.h>

// Definerer en struktur for en node i den lenkede listen
typedef struct node
{
    int data;          // Data som lagres i noden
    struct node *next; // Pekeren til neste node
} node;

// Funksjonsprototyper
void insert_sorted(node **head, int number);
void print_list(node *head);
void free_list(node *head);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./cslist <data>\n");
        return 1;
    }

    node *list = NULL;

    // Går gjennom alle kommandolinjeargumentene og setter inn noder i sortert rekkefølge
    for (int index = 1; index < argc; index++)
    {
        int number = atoi(argv[index]);
        insert_sorted(&list, number);
    }

    // Skriver ut innholdet i den lenkede listen
    print_list(list);

    // Frigjør minne for hver node i listen
    free_list(list);

    return 0;
}

// Funksjon for å sette inn en ny node i sortert rekkefølge
void insert_sorted(node **head, int number)
{
    // Allokerer minne for en ny node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(2);
    }
    
    new_node->data = number;
    new_node->next = NULL;

    // Hvis listen er tom eller nummeret skal være før hodet
    if (*head == NULL || (*head)->data >= number)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        // Finn riktig plass for den nye noden
        node *current = *head;
        while (current->next != NULL && current->next->data < number)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Funksjon for å skrive ut listen
void print_list(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Funksjon for å frigjøre minne for hele listen
void free_list(node *head)
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
