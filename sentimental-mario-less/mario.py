# Ber brukeren om å skrive inn høyden
while True:
    try:
        height = int(input("Height: "))  # Forsøker å konvertere til et heltall
        if height >= 1 and height <= 8:
            break  # Godtar høyden dersom den er mellom 1 og 8
        else:
            print("Please enter a height between 1 and 8.")
    except ValueError:
        print("Please enter a valid integer.")  # Avviser ikke-numerisk input

# Løper gjennom hver rad og skriver ut riktig antall mellomrom og # for å lage pyramiden
for index in range(height):
    print(" " * (height - index - 1) + "#" * (index + 1))
