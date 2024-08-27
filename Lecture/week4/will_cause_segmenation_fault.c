#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    char *s = get_string("Before: ");
    char *t = s;
    
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("After: %s\n", t);
}