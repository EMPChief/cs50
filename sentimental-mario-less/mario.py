# Mario funksjon for og printer pyramiden.
def mario():
    # Bær bruker om å skrive inn høyden.
    while True:
        # Try løkken sjekker om input er et tall.
        try:
            height = int(input("Height: "))
            # If-testen sjekker om tall er mellom 1 og 8.
            if height >= 1 and height <= 8:
                break
            # else så seier om at er feil og gjør det igjen.
            else:
                print("Please enter a height between 1 and 8.")
        # Except-testen sjekker om input er et tall.
        except ValueError:
            print("Please enter a valid integer.")
    # for løkken lager pyramiden.
    for index in range(height):
        print(" " * (height - index - 1) + "#" * (index + 1))


def main():
    mario()


if __name__ == "__main__":
    main()

