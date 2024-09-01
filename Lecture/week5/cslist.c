#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./cslist <data>\n");
        return 1;
    }
    node *list = NULL;

    for (int index = 2; index < argc; index++)
    {
        int number = atoi(argv[index]);
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            return 2;
        }
        new->data = number;
        new->next = list;
        list = new;
    }

    node *cursor = list;
    while (cursor != NULL)
    {
        printf("%i\n", cursor->data);
        cursor = cursor->next;
    }

    free(list);

    return 0;
}