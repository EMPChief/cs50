#include <stdio.h>
#include <stdlib.h>

// Funksjonsprototyper
float get_float(const char *prompt);
char get_operator();
float calculate(float first_number, float second_number, char operator);

int main()
{
    // Hent første tall fra brukeren
    float first_number = get_float("Enter first number: ");

    // Hent andre tall fra brukeren
    float second_number = get_float("Enter second number: ");

    // Hent operator fra brukeren
    char operator= get_operator();

    // Utfør beregning basert på input og håndter deling med null
    float result = calculate(first_number, second_number, operator);

    // Skriv ut resultatet av beregningen
    printf("Result: %.2f\n", result);

    return 0;
}

// Funksjonsdefinisjoner

// Henter en flyttallsverdi fra brukeren med et spesifisert prompt
float get_float(const char *prompt)
{
    float number;
    char input[100];

    while (1)
    {
        // Skriv ut prompt til brukeren
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            // Forsøk å konvertere input til et flyttall
            if (sscanf(input, "%f", &number) == 1)
            {
                return number; // Returner det konverterte flyttallet
            }
        }
        // Hvis konverteringen mislykkes, skriv ut en feilmelding
        printf("Invalid input. Please enter a valid number.\n");
    }
}

// Henter en operator fra brukeren og validerer at den er gyldig
char get_operator()
{
    char operator;
    while (1)
    {
        // Skriv ut prompt for å hente operator
        printf("Enter operator: (+, -, *, /): ");
        scanf(" %c", &operator);

        // Sjekk om operatoren er gyldig
        if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        {
            return operator; // Returner den gyldige operatoren
        }

        // Hvis operatoren ikke er gyldig, skriv ut en feilmelding
        printf("Invalid operator. Please enter one of +, -, *, /.\n");
    }
}

// Utfører en beregning basert på de to tallene og operatoren
float calculate(float first_number, float second_number, char operator)
{
    switch (operator)
    {
    case '+':
        // Utfør addisjon
        return first_number + second_number;
    case '-':
        // Utfør subtraksjon
        return first_number - second_number;
    case '*':
        // Utfør multiplikasjon
        return first_number * second_number;
    case '/':
        // Håndter divisjon og sjekk for deling med null
        if (second_number == 0)
        {
            printf("Cannot divide by zero.\n"); // Kan ikke dele med null
            exit(1);
        }
        return first_number / second_number;
    default:
        // Håndter ugyldig operator
        printf("Invalid operator.\n"); // Ugyldig operator
        exit(1);
    }
}
