#include <stdio.h>

// Funksjon prototype
void modifyValue(int x);

int main()
{
    int num = 5;
    printf("Før funksjonskall: %d\n", num);

    // Kaller funksjonen som modifiserer den lokale kopien av x
    modifyValue(num);

    // Etter funksjonskallet forblir num uendret fordi kun kopien av verdien ble modifisert
    printf("Etter funksjonskall: %d\n", num); // num forblir uendret

    return 0;
}

// Funksjonen modifiserer verdien av den lokale kopien av x, ikke den opprinnelige variabelen
void modifyValue(int x)
{
    x = x * 2; // Dette endrer bare kopien av x i funksjonen
    printf("Inne i funksjonen: %d\n", x);
}