# Week 4: Memory Management and Pointers

This document provides a comprehensive overview of Week 4 topics in CS50, covering memory management, pointers, and dynamic memory allocation in C.

## Table of Contents
1. [Memory Basics](#memory-basics)
2. [Pointers](#pointers)
3. [Dynamic Memory Allocation](#dynamic-memory-allocation)
4. [Common Memory Issues](#common-memory-issues)
5. [String Manipulation with Pointers](#string-manipulation-with-pointers)
6. [Code Examples](#code-examples)

## Memory Basics

### Memory Layout
- Stack: Local variables, function calls
- Heap: Dynamically allocated memory
- Data: Global variables
- Text: Program code

### Memory Addresses
```c
// From printing_memory_address.c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);  // Print memory address of n
    return 0;
}
```

## Pointers

### Pointer Basics
- A pointer is a variable that stores a memory address
- Declared using the * operator
- & operator gets the address of a variable

### Pointer Arithmetic
```c
// From Pointer_Arithmetic_with_Arrays.c
#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    printf("%i\n", *numbers);        // First element
    printf("%i\n", *(numbers + 1));  // Second element
    printf("%i\n", *(numbers + 2));  // Third element
    return 0;
}
```

### Passing by Reference
```c
// From swap.c
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

## Dynamic Memory Allocation

### malloc and free
```c
// From malloc_and_free.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate space for an integer
    int *x = malloc(sizeof(int));
    
    // Check if allocation was successful
    if (x == NULL)
    {
        return 1;
    }
    
    // Use the allocated memory
    *x = 42;
    printf("%i\n", *x);
    
    // Free the allocated memory
    free(x);
    return 0;
}
```

### calloc
```c
// From calloc.c
int *arr = calloc(4, sizeof(int));  // Allocates and initializes to 0
```

### realloc
```c
// From realloc.c
int *temp = realloc(arr, new_size * sizeof(int));
```

## Common Memory Issues

### Memory Leaks
- Failing to free allocated memory
- Example of proper cleanup:
```c
int *x = malloc(sizeof(int));
// ... use x ...
free(x);  // Don't forget this!
```

### Segmentation Faults
Common causes:
1. Dereferencing NULL pointers
2. Accessing memory out of bounds
3. Using freed memory

Example that will cause segmentation fault:
```c
// From will_cause_segmenation_fault.c
int main(void)
{
    int *x;
    printf("%i\n", *x);  // Accessing uninitialized pointer
    return 0;
}
```

### Buffer Overflow
```c
// Dangerous code - potential buffer overflow
char buffer[5];
gets(buffer);  // Never use gets()!

// Safe alternative
char buffer[5];
fgets(buffer, sizeof(buffer), stdin);
```

## String Manipulation with Pointers

### String Operations
```c
// From String_Manipulation_and_Memory_Addresses.c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello!";
    printf("%c\n", *s);       // First character
    printf("%c\n", *(s+1));   // Second character
    printf("%s\n", s);        // Entire string
    
    // Print each character using pointer arithmetic
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c\n", *(s+i));
    }
    return 0;
}
```

## Code Examples

### Phone Book Implementation
A more complex example using dynamic memory allocation and file I/O:
```c
// Excerpt from phonebook.c
typedef struct
{
    char *name;
    char *number;
} person;

// Create array of people
person *people = malloc(sizeof(person) * capacity);
if (people == NULL)
{
    return 1;
}

// Add person to phone book
people[size].name = strdup(name);    // Allocate memory for name
people[size].number = strdup(number); // Allocate memory for number
size++;
```

## Practice Problems

1. Implement a function that reverses a string using pointers
2. Create a dynamic array that resizes itself when full
3. Write a program that detects memory leaks
4. Implement a linked list using dynamic memory allocation

## Common Pitfalls to Avoid

1. Always check if malloc/calloc/realloc succeeded
2. Free all allocated memory
3. Don't use freed memory
4. Don't dereference NULL pointers
5. Check array bounds before accessing elements

## Additional Resources

- [CS50 Memory Notes](https://cs50.harvard.edu/x/2024/notes/4/)
- [Valgrind Memory Checker](https://valgrind.org/)
- [GDB Debugger Guide](https://www.gnu.org/software/gdb/) 