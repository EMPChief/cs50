# Pixels and Pointers

## Pixels

### Basic Concept
- A picture is a collection of pixels arranged in a grid to form an image.
- In the simplest form, each pixel can be 0 or 1, representing black or white respectively.

### Example: Smiley Face

- 1 1 0 0 0 0 1 1
- 1 0 1 1 1 1 0 1
- 0 1 0 1 1 0 1 0
- 0 1 1 1 1 1 1 0
- 0 1 0 1 1 0 1 0
- 0 1 1 0 0 1 1 0
- 1 0 1 1 1 1 0 1
- 1 1 0 0 0 0 1 1


### RGB Color Model
- Pixels on a computer are typically represented using the RGB color model.
- RGB is a 3D vector where (0,0,0) represents black and (255,255,255) represents white.
- In software like Photoshop, colors are represented as:
  - Red: FF 00 00
  - Green: 00 FF 00
  - Blue: 00 00 FF

### Hex Color Codes
- Hex color codes use characters 0-9 and A-F (or a-f) to represent colors in base-16.
- Examples:
  - #000000: Black
  - #FFFFFF: White
  - #FF0000: Red
  - #00FF00: Green
  - #0000FF: Blue
  - #FF00FF: Magenta
  - #00FFFF: Cyan
- To distinguish hex numbers, we often prefix them with "0x" (e.g., 0x0, 0x1, 0x2, etc.)

## Pointers

### Pointers in C
- A pointer is a variable that stores the memory address of another variable.
- The "&" operator is used to get the memory address of a variable.
- The "*" operator is used to access the value stored at a memory address.
- To check the memory address within the same function, use `(void*)&variable`.

### Pointer Arithmetic
- Pointer arithmetic allows you to perform arithmetic operations on pointers.
- Example: If `ptr` is a pointer to an integer, `ptr++` will increment the pointer to the next integer in memory.
- This feature is useful for efficient array iteration.

### typedef
- A typedef is a type definition that allows you to create an alias for an existing type.
- For example, `typedef int myint` will create an alias for the `int` type called `myint`.
- This feature is useful when you want to simplify type declarations.

### Example: Typedef with Structures
```c
typedef struct
{
  char *name;
  int age;
} Person;
```
Example: Typedef for uint8_t
```c
typedef uint8_t byte;
```
- This will create an alias for the `uint8_t` type called `byte`.
- it is often used in header files.
- the code used in cs50 is as follows
```c
typedef char *string;
```


### Example: Printing Memory Address
```c
#include <stdio.h>

int main(void)
{
    int number = 5;
    printf("The address of the variable 'number' is: %p\n", (void*)&number);
    return 0;
}
```
### Example: Pointer Arithmetic with Arrays

```c

int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr; // ptr points to the first element of arr
for (int i = 0; i < 5; i++) {
    printf("%d ", *ptr); // Print the value pointed by ptr
    ptr++; // Move ptr to the next element
}
```
### Example: String Manipulation and Memory Addresses
```c
#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    string greeting = "Hello There"; // Initialiserer en streng med hilsenen
    printf("%s\n", greeting);        // Skriv ut strengen
    printf("%p\n", greeting);        // Skriv ut minneadressen til strengen
    printf("%p\n", &greeting[0]);    // Skriv ut minneadressen til det første tegnet i strengen
    
    int length = strlen(greeting);   // Finner lengden på strengen
    for (int index = 0; index < length; index++)
    {
        printf("%c\n", greeting[index]);  // Skriv ut hvert tegn i strengen
        printf("%p\n", &greeting[index]); // Skriv ut minneadressen til hvert tegn
    }
    return 0;
}
```
### Example: String Manipulation and Memory Addresses (removed cs50 header)
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *greeting = "Hello There"; // Initialiserer en streng med hilsenen
    printf("%s\n", greeting);        // Skriv ut strengen
    printf("%p\n", greeting);        // Skriv ut minneadressen til strengen
    printf("%p\n", &greeting[0]);    // Skriv ut minneadressen til det første tegnet i strengen
    
    int length = strlen(greeting);   // Finner lengden på strengen
    for (int index = 0; index < length; index++)
    {
        printf("%c\n", greeting[index]);  // Skriv ut hvert tegn i strengen
        printf("%p\n", &greeting[index]); // Skriv ut minneadressen til hvert tegn
    }
    return 0;
}
```