def get_credit_card_number():
    """
    Henter et kredittkortnummer fra brukeren og sikrer at det er et ikke-negativt heltall.

    Returns:
        int: Kredittkortnummeret som er oppgitt av brukeren.
    """
    while True:
        try:
            # Be om kredittkortnummer fra brukeren
            card_number = int(input("Enter your credit card number: "))
            if card_number >= 0:
                return card_number
        except ValueError:
            # Håndterer tilfeller med ugyldig input
            print("Invalid input. Please enter a sequence of digits only.")


def check_card_type(card_number, count):
    """
    Bestemmer korttypen basert på kortnummerets lengde og spesifikasjoner.

    Args:
        card_number (int): Kredittkortnummeret som skal sjekkes.
        count (int): Antall sifre i kortnummeret.

    Returns:
        str: Korttypen som en streng ("AMEX", "MASTERCARD", "VISA", eller "INVALID").
    """
    if count == 15 and (card_number // 10**13 in [34, 37]):
        return "AMEX"
    elif count == 16 and (card_number // 10**14 in [51, 52, 53, 54, 55]):
        return "MASTERCARD"
    elif (count == 13 or count == 16) and (card_number // 10**(count-1) == 4):
        return "VISA"
    else:
        return "INVALID"


def main():
    """
    Hovedfunksjonen som håndterer input, validerer kredittkortnummeret ved hjelp av Luhn-algoritmen,
    og bestemmer korttypen.
    """
    # Hent kredittkortnummer fra brukeren
    card_number = get_credit_card_number()

    sum_digits = 0
    count = 0

    temp_card = card_number

    # Beregn summen av sifrene basert på Luhn-algoritmen
    while temp_card > 0:
        digit = temp_card % 10

        if count % 2 == 0:
            # Legg til verdien av det nåværende sifferet
            sum_digits += digit
        else:
            # Dobbel sifferverdien og legg til summen av siftene
            product = 2 * digit
            sum_digits += product % 10 + product // 10

        count += 1
        temp_card //= 10

    # Sjekk om summen er delelig med 10 og bestem korttypen
    if sum_digits % 10 == 0:
        print(check_card_type(card_number, count))
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
