#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    char *s = get_string("Before: ");
    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        printf("Memory allocation failed.\n");
        return 2;
    }

    strcpy(t, s);
    
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("After: %s\n", t);
    free(t);
    return 0;
}