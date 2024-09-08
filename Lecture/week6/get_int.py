def get_str(prompt):
    while True:
        try:
            return str(input(prompt))
        except ValueError:
            print("Please enter a valid string.")


def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Please enter a valid integer.")


def get_float(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Please enter a valid float.")


def main():
    user_str = get_str("Enter a string: ")
    user_int = get_int("Enter an integer: ")
    user_float = get_float("Enter a float: ")

    print(f"You entered string: {user_str}")
    print(f"You entered integer: {user_int}")
    print(f"You entered float: {user_float}")


if __name__ == "__main__":
    main()
