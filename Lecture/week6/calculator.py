import math

def get_float(prompt):
    # Henter en flyttallsverdi fra brukeren med et spesifisert prompt
    while True:
        try:
            # Konverterer input til flyttall og returnerer det
            return float(input(prompt))
        except ValueError:
            # Feilmelding for ugyldig input
            print("Invalid input. Please enter a valid number.")

def get_operator():
    # Henter operatoren fra brukeren og validerer at den er gyldig
    while True:
        operator = input("Enter operator: (+, -, *, /): ")
        if operator in ("+", "-", "*", "/"):
            # Returnerer den gyldige operatoren
            return operator
        # Feilmelding for ugyldig operator
        print("Invalid operator. Please enter one of +, -, *, /.")

def calculate(first_number, second_number, operator):
    # Utfører beregning basert på operatoren og de to tallene
    match operator:
        case "+":
            # Utfører addisjon
            return first_number + second_number
        case "-":
            # Utfører subtraksjon
            return first_number - second_number
        case "*":
            # Utfører multiplikasjon
            return first_number * second_number
        case "/":
            if second_number == 0:
                # Håndterer deling med null
                raise ZeroDivisionError("Cannot divide by zero")
            # Utfører divisjon
            return first_number / second_number

def main():
    # Henter første tall fra brukeren
    first_number = get_float("Enter first number: ")
    # Henter andre tall fra brukeren
    second_number = get_float("Enter second number: ")
    # Henter operator fra brukeren
    operator = get_operator()
    try:
        # Utfører beregningen
        result = calculate(first_number, second_number, operator)
        # Skriv ut resultatet
        print(result)
    except ZeroDivisionError as e:
        # Håndterer og skriver ut feilmelding ved deling med null
        print(e)

if __name__ == "__main__":
    # Kaller main-funksjonen når skriptet kjøres
    main()
