# Variabel for å holde mengden som skal endres
change_owed = 0
is_valid_input = False

# Spør brukeren om mengden endring tilknyttet og valider inndata
while not is_valid_input:
    try:
        # Forsøker å konvertere til et flyttall
        change_owed = float(input("Change owed: "))
        if change_owed > 0:
            is_valid_input = True  # Godtar innput dersom det er et positivt tall
        else:
            print("Invalid input. Please enter a positive number.")
    except ValueError:
        # Håndterer ikke-numerisk input
        print("Invalid input. Please enter a positive number.")

# Konverter til hele cent
change_owed = round(change_owed * 100)

# Variabler for antall mynter
number_of_quarters = 0
number_of_dimes = 0
number_of_nickels = 0
number_of_pennies = 0

# Beregn antall kvartaler (25¢)
while change_owed >= 25:
    change_owed -= 25
    number_of_quarters += 1

# Beregn antall deser (10¢)
while change_owed >= 10:
    change_owed -= 10
    number_of_dimes += 1

# Beregn antall nickler (5¢)
while change_owed >= 5:
    change_owed -= 5
    number_of_nickels += 1

# Beregn antall pennere (1¢)
while change_owed >= 1:
    change_owed -= 1
    number_of_pennies += 1

# Beregn totalt antall mynter
total_number_of_coins = number_of_quarters + \
    number_of_dimes + number_of_nickels + number_of_pennies

print(f"{total_number_of_coins}")
