#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    string greeting = "Hello There"; // Initialiserer en streng med hilsenen
    printf("%s\n", greeting);        // Skriv ut strengen
    printf("%p\n", greeting);        // Skriv ut minneadressen til strengen
    printf("%p\n", &greeting[0]);    // Skriv ut minneadressen til det første tegnet i strengen
    
    int length = strlen(greeting);   // Finner lengden på strengen
    for (int index = 0; index < length; index++)
    {
        printf("%c\n", greeting[index]);  // Skriv ut hvert tegn i strengen
        printf("%p\n", &greeting[index]); // Skriv ut minneadressen til hvert tegn
    }
    return 0;
}