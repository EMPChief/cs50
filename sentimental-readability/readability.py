# Denne skripten beregner lesbarhetsgraden av en tekst ved å bruke Coleman-Liau-indeksen.
# Coleman-Liau-indeksen beregnes med formelen:
#     Index = 0.0588 * L - 0.296 * S - 15.8
# der L er det gjennomsnittlige antallet bokstaver per 100 ord og S er det gjennomsnittlige antallet setninger per 100 ord.
# Skripten teller bokstaver, ord og setninger i den angitte teksten, beregner indeksen,
# og skriver ut den tilsvarende karaktergraden.

text = input("Text: ")

# Initialiser tellere for bokstaver, ord og setninger
letters = 0
words = 1  # Start med 1 for å telle det første ordet
sentences = 0

# Gå gjennom hver karakter i teksten
for character in text:
    if character.isalpha():
        letters += 1
    elif character.isspace():
        words += 1
    elif character in [".", "!", "?"]:
        sentences += 1

# Beregn det gjennomsnittlige antallet bokstaver og setninger per 100 ord
L = (letters / words) * 100
S = (sentences / words) * 100

# Beregn Coleman-Liau-indeksen
index = 0.0588 * L - 0.296 * S - 15.8

# Rund av indeksen til nærmeste heltall
grade = round(index)

# Bestem karaktergraden for utskriften
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")
