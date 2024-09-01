#include <stdio.h>
#include "cs50.h"

int main(void)
{
    // Deklarerer tegn
    char c1 = 'H';
    char c2 = 'e';
    char c3 = 'l';
    char c4 = 'o';

    // Skriver ut tegnene sammen
    printf("%c%c%c%c%c\n", c1, c2, c3, c3, c4);

    // Deklarerer strenger
    string s = "Hello!";
    string t = "Bye!";

    // Skriver ut ASCII-verdier av tegnene i strengene
    // Merk: Indeksen må være innenfor strengens lengde
    printf("%i %i %i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    printf("%i %i %i %i %i %i %i\n", t[0], t[1], t[2], t[3], t[4], t[5], t[6]);

    // Skriver ut strengene
    printf("%s\n", s);
    printf("%s\n", t);

    // Deklarerer et array av strenger
    string words[2];
    words[0] = "Hello";
    words[1] = "World";

    // Skriver ut elementene i arrayet
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);

    // Skriver ut begge strengene på en linje
    printf("%s %s\n", words[0], words[1]);

    // Skriver ut hver bokstav i strengene i arrayet
    // Merk: Indeksen må være innenfor lengden på strengene
    printf("%c%c%c%c%c\n", words[0][0], words[0][1], words[0][2], words[0][3], words[0][4]);
    printf("%c%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3], words[1][4]);

    // Forsøker å få tilgang til indekser utenfor lengden av strengene
    // Dette vil føre til uberegnelige resultater og potensielle krasj
    // Derfor er denne linjen feil og bør ikke brukes
    printf("%c%c%c%c%c\n", words[0][6], words[0][7], words[0][8], words[0][9], words[0][10]);

    return 0;
}
