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
### malloc and free

- `malloc` and `free` are functions in the C standard library for dynamic memory management.
- `malloc` (memory allocation) allocates a specified number of bytes in the heap.
- `free` deallocates memory that was previously allocated by `malloc`, `calloc`, or `realloc`.

#### malloc
- Syntax: `void *malloc(size_t size)`
- Returns a pointer to the allocated memory, or NULL if the allocation fails.
- The allocated memory is uninitialized.

#### free
- Syntax: `void free(void *ptr)`
- Deallocates the memory block pointed to by `ptr`.
- `ptr` must have been returned by a previous call to `malloc`, `calloc`, or `realloc`.

#### Example: Using malloc and free

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *hello = malloc(6 * sizeof(char));  // Allocate space for 5 chars + null terminator
    if (hello == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    hello[0] = 'H';
    hello[1] = 'e';
    hello[2] = 'l';
    hello[3] = 'l';
    hello[4] = 'o';
    hello[5] = '\0';  // Null terminator

    printf("%s\n", hello);
    free(hello);
    return 0;
}
```
### realloc
- realloc is used to resize a previously allocated memory block.
- Syntax: void *realloc(void *ptr, size_t new_size)
- Returns a pointer to the reallocated memory, or NULL if the reallocation fails
- If ptr is NULL, realloc behaves like malloc.
- If new_size is 0 and ptr is not NULL, realloc behaves like free.

### Example: Using realloc
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *hello = malloc(6 * sizeof(char));
    if (hello == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(hello, "Hello");
    printf("%s\n", hello);

    hello = realloc(hello, 11 * sizeof(char));
    if (hello == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    strcat(hello, " World");
    printf("%s\n", hello);

    free(hello);
    return 0;
}
```
### calloc
- calloc allocates memory for an array of elements and initializes all bytes to zero.
- Syntax: void *calloc(size_t num_elements, size_t element_size)
- The `calloc` function allows you to allocate the memory allocation pointed to by `ptr` to `bytes`
- Returns a pointer to the allocated memory, or NULL if the allocation fails.

### Example: Using calloc
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numbers = calloc(5, sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);  // Will print "0 0 0 0 0"
    }
    printf("\n");

    free(numbers);
    return 0;
}
```
### sizeof
- sizeof is an operator (not a function) that returns the size in bytes of a type or variable.
- Syntax: sizeof(type) or sizeof expression
- 's evaluated at compile-time, not at runtime

### Example: Using sizeof
```c
#include <stdio.h>

int main(void)
{
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));

    int numbers[] = {1, 2, 3, 4, 5};
    printf("Size of numbers array: %zu bytes\n", sizeof(numbers));
    printf("Number of elements in numbers array: %zu\n", sizeof(numbers) / sizeof(numbers[0]));

    return 0;
}
```


### Example: Comparing Strings with Pointers and Arrays and get user input
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *first = malloc(80 * sizeof(char));
    char *second = malloc(80 * sizeof(char));
    
    if (first == NULL || second == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("First: ");
    fgets(first, 80, stdin);
    first[strcspn(first, "\n")] = 0;

    printf("Second: ");
    fgets(second, 80, stdin);
    second[strcspn(second, "\n")] = 0;

    if (strcmp(first, second) == 0)
    {
        printf("The strings are the same: %s | %s\n", first, second);
    }
    else
    {
        printf("The strings are different: %s | %s\n", first, second);
    }

    free(first);
    free(second);
    return 0;
}
```
### Example: Printing Characters with Pointers and Arrays
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *greeting = "Hello There";
    printf("%c\n", *greeting);
    printf("%c\n", *(greeting + 1));
    printf("%c\n", *(greeting + 2));
    printf("%c\n", *(greeting + 3));
    printf("%c\n", *(greeting + 4));
    int length = strlen(greeting);
    for (int index = 0; index < length; index++)
    {
        printf("%c\n", *(greeting + index));
    }
    return 0;
}

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
### Example: Malloc and Free and Memory Addresses
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *first = malloc(80 * sizeof(char));
    char *second = malloc(80 * sizeof(char));
    
    if (first == NULL || second == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("First: ");
    fgets(first, 80, stdin);
    first[strcspn(first, "\n")] = 0;

    printf("Second: ");
    fgets(second, 80, stdin);
    second[strcspn(second, "\n")] = 0;

    printf("Memory address of first: %p\n", first);
    printf("Memory address of second: %p\n", second);

    free(first);
    free(second);
    return 0;
}
```
### Example: This will cause a segmentation fault
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    char *s = get_string("Before: ");
    char *t = s;
    
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("After: %s\n", t);
}
```
### Example: This will not cause a segmentation fault
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <ctype.h>

int main(void)
{
    char *s = get_string("Before: ");
    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        printf("Memory allocation failed.\n");
        return 2;
    }

    strcpy(t, s);
    
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("After: %s\n", t);
    free(t);
    return 0;
}
```