string = input("Do you agree? ").lower()

if string in ("yes", "y"):
    print(
        "“Success is not final, failure is not fatal: It is the courage to continue that counts.” – Winston Churchill"
    )
elif string in ("no", "n"):
    print("“The only way to do great work is to love what you do.” – Steve Jobs")
else:
    print(
        "“The only real mistake is the one from which we learn nothing.” – Henry Ford"
    )
