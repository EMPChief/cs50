#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Skriv ut en oppfordring for å få kredittkortnummer fra brukeren
    printf("Enter your credit card number: ");

    // Deklarer en variabel for å lagre kredittkortnummeret
    long card_number;

    // Hent kredittkortnummer fra brukeren, med validering for å sikre at det ikke er negativt
    do
    {
        // Bruk get_long for å få et langt heltall fra brukeren
        card_number = get_long("Enter your credit card number: ");
    }
    while (card_number < 0);

    // Variabler for sum og antall for å følge algoritmen
    int sum = 0;
    int count = 0;

    // Midlertidig variabel for å lagre det originale kortnummeret for behandling
    long temp = card_number;

    // Sløyfe for å behandle hvert siffer av kortnummeret
    while (temp > 0)
    {
        // Få det siste sifferet av kortnummeret
        int digit = temp % 10;

        // Sjekk om sifferet er på en jevn eller odd posisjon
        if (count % 2 == 0)
        {
            // Hvis jevnt, legg til sifferet til summen
            sum += digit;
        }
        else
        {
            // Hvis odd, dobbel sifferet og legg til sifrene til summen
            int product = 2 * digit;
            sum += product % 10 + product / 10;
        }

        // Gå til neste siffer ved å dele den midlertidige variabelen
        temp /= 10;

        // Øk antallet for å følge med på posisjonen
        count++;
    }

    // Sjekk om summen er delelig med 10
    if (sum % 10 == 0)
    {
        // Sjekk om kortnummerets lengde og start sifre matcher AMEX
        if ((count == 15 || count == 16) && (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37))
        {
            // Skriv ut AMEX for American Express
            printf("AMEX\n");
        }
        // Sjekk om kortnummerets lengde og start sifre matcher MASTERCARD
        else if (count == 16 && (card_number / 100000000000000 == 51 || card_number / 100000000000000 == 52 ||
                                card_number / 100000000000000 == 53 || card_number / 100000000000000 == 54 ||
                                card_number / 100000000000000 == 55))
        {
            // Skriv ut MASTERCARD for MasterCard
            printf("MASTERCARD\n");
        }
        // Sjekk om kortnummerets lengde og start sifre matcher VISA
        else if ((count == 13 || count == 16) && (card_number / 1000000000000 == 4 || card_number / 1000000000000000 == 4))
        {
            // Skriv ut VISA for Visa
            printf("VISA\n");
        }
        // Hvis det ikke matcher noen kjente korttyper, skriv ut INVALID
        else
        {
            printf("INVALID\n");
        }
    }
    // Hvis summen ikke er delelig med 10, skriv ut INVALID
    else
    {
        printf("INVALID\n");
    }

    // Returner 0 for å indikere vellykket programkjøring
    return 0;
}
