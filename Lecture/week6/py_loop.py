before = ["apple", "banana", "cherry"]


print("Using for loop:")
for b in before:
    print(b.upper(), end=" ")
print()

print("Using while loop:")
i = 0
while i < len(before):
    print(before[i].upper(), end=" ")
    i += 1
print()

