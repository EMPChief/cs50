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

### realloc
- `realloc` is used to resize a previously allocated memory block.
- Syntax: `void *realloc(void *ptr, size_t new_size)`
- Returns a pointer to the reallocated memory, or NULL if the reallocation fails.
- If `ptr` is NULL, `realloc` behaves like `malloc`.
- If `new_size` is 0 and `ptr` is not NULL, `realloc` behaves like `free`.

### calloc
- `calloc` allocates memory for an array of elements and initializes all bytes to zero.
- Syntax: `void *calloc(size_t num_elements, size_t element_size)`
- Returns a pointer to the allocated memory, or NULL if the allocation fails.

### sizeof
- `sizeof` is an operator (not a function) that returns the size in bytes of a type or variable.
- Syntax: `sizeof(type)` or `sizeof expression`
- It's evaluated at compile-time, not at runtime.

### strcpy
- `strcpy` is a function used to copy strings.
- Syntax: `char *strcpy(char *dest, const char *src)`
- Copies the C string pointed by `src` into the array pointed by `dest`, including the terminating null character.
- Returns a pointer to the destination string `dest`.
- Warning: It doesn't check for buffer overflows, so it's recommended to use `strncpy` instead.

### strcat
- `strcat` is a function used to concatenate strings.
- Syntax: `char *strcat(char *dest, const char *src)`
- Appends a copy of the source string `src` to the end of the destination string `dest`.
- The terminating null character in `dest` is overwritten by the first character of `src`.
- Returns a pointer to the resulting string `dest`.

### strcmp
- `strcmp` is a function used to compare strings.
- Syntax: `int strcmp(const char *str1, const char *str2)`
- Compares the C string `str1` to the C string `str2`.
- Returns an integer less than, equal to, or greater than zero if `str1` is found, respectively, to be less than, to match, or be greater than `str2`.

### strlen
- `strlen` is a function used to get the length of a string.
- Syntax: `size_t strlen(const char *str)`
- Computes the length of the C string `str` up to, but not including the terminating null character.
- Returns the number of characters in the string.

### Valgrind

Valgrind is a powerful suite of debugging and profiling tools for Linux and macOS programs. It's particularly useful for detecting memory-related errors and memory leaks in C and C++ programs.

#### Key Features:
- Memory error detection
- Memory leak detection
- Profiling
- Thread error detection

#### Common Use:
The most commonly used tool in Valgrind is Memcheck, which detects memory-related errors.

#### How to Use:
1. Compile your program with debugging symbols (use the `-g` flag): gcc -g your_program.c -o your_program
2. Run your program through Valgrind:: ./your_program
#### What Valgrind Detects:
- Use of uninitialized memory
- Reading/writing memory after it has been freed
- Reading/writing off the end of malloc'd blocks
- Memory leaks
- Use of inappropriate malloc/free/new/delete/new[]/delete[] pairs
- Overlapping src and dst pointers in memcpy() and related functions
#### Tips:
- Always compile with `-g` for debugging symbols.
- Use `--leak-check=full` for detailed leak information:

### garbage values
- garbage values are values that are not used in a program and cause undefined behavior.
- For example, the value 0 is a garbage value because it is not used in any arithmetic expression.
