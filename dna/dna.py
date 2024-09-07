import csv
import sys


def main():

    # TODO: Sjekk om kommando-linje bruk er riktig
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Les databasefilen inn i en variabel
    # Åpne CSV-filen som er gitt som argument og les inn dataene.
    # Bruk csv.reader for å parse filen og lagre informasjonen i en variabel.
    # Denne variabelen skal inneholde informasjon om personer og deres STR-frekvenser.
    with open(sys.argv[1], "r") as database_file:
        reader = csv.DictReader(database_file)
        database = [row for row in reader]

    # TODO: Les DNA-sekvensfilen inn i en variabel
    # Åpne tekstfilen som er gitt som argument og les inn DNA-sekvensen.
    # Lagre sekvensen som en enkel streng i en variabel.
    with open(sys.argv[2], "r") as sequence_file:
        sequence = sequence_file.read()

    # TODO: Finn lengste sekvens av hver STR i DNA-sekvensen
    # For hver STR i databasen, kall longest_match-funksjonen
    # for å finne lengden på den lengste sekvensen av STR-en i DNA-sekvensen.
    # Lagre resultatene i en variabel for senere sammenligning.
    str_counts = {}
    for key in database[0].keys():
        if key == "name":
            continue
        str_counts[key] = longest_match(sequence, key)

    # TODO: Sjekk databasen for matchende profiler
    # Sammenlign STR-tellene med dataene i databasen for å finne en match.
    # Hvis en match blir funnet, skriv ut navnet til personen som matcher.
    for person in database:
        match = True
        for key in person.keys():
            if key == "name":
                continue
            if int(person[key]) != str_counts[key]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
