#include <stdio.h>
#include <string.h>

int main(void)
{
    // Pekeren 'greeting' peker til en konstant streng "Hello There"
    char *greeting = "Hello There";

    // Skriver ut hvert tegn i strengen en etter en ved å bruke pekeren
    printf("%c\n", *greeting);       // Skriver ut det første tegnet: 'H'
    printf("%c\n", *(greeting + 1)); // Skriver ut det andre tegnet: 'e'
    printf("%c\n", *(greeting + 2)); // Skriver ut det tredje tegnet: 'l'
    printf("%c\n", *(greeting + 3)); // Skriver ut det fjerde tegnet: 'l'
    printf("%c\n", *(greeting + 4)); // Skriver ut det femte tegnet: 'o'

    // Finner lengden på strengen 'greeting'
    int length = strlen(greeting);

    // Løkke for å skrive ut hvert tegn i strengen basert på lengden
    for (int index = 0; index < length; index++)
    {
        printf("%c\n", *(greeting + index)); // Skriver ut tegnene i strengen ett om gangen
    }

    return 0;
}
