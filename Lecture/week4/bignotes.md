# Usefull links:
- [Binky Pointer Fun Video C](https://www.youtube.com/watch?v=5VnDaHBi8dM)
- [Dynamic Memory Allocation in C](https://www.youtube.com/watch?v=Dn87Bna23TQ)
- [C Pointers](https://www.youtube.com/watch?v=KGhacRRMnDw)
- [Structure Types (Using typedef)](https://www.youtube.com/watch?v=Bw3sUC6Txus)
- [Standard C Library Functions Table, By Name](https://www.ibm.com/docs/en/i/7.5?topic=extensions-standard-c-library-functions-table-by-name)
- [CS50x 2024 - Lecture 4 - Memory](https://www.youtube.com/watch?v=F9-yqoS7b8w)

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

### scanf
- scanf is a function used to read formatted input from the standard input (usually the keyboard).
- Syntax: int scanf(const char *format, ...)
- Reads data from the standard input and stores it according to the format specified in the format string.
- The format string can include format specifiers that determine how to interpret the input data. Common format specifiers include %d for integers, %f for floating-point numbers, and %s for strings.

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

### Garbage Values

Garbage values are unpredictable and undefined values that exist in uninitialized memory locations. They are not specifically unused values, but rather values that haven't been intentionally set by the program.

Key points about garbage values:

1. Definition: Garbage values are the contents of uninitialized variables or memory locations.

2. Cause: They occur when memory is allocated but not initialized with a specific value.

3. Unpredictability: The actual content of garbage values can be anything - it's whatever data happened to be in that memory location from previous usage.

4. Undefined Behavior: Using garbage values can lead to undefined behavior in a program, potentially causing bugs or crashes.

5. Common occurrences:
   - Uninitialized local variables in C
   - Uninitialized dynamically allocated memory

6. Prevention: Always initialize variables before use, and set allocated memory to known values if needed.

- In the example, x contains a garbage value because it was not initialized.
- Note: The value 0 is not inherently a garbage value. It becomes a garbage value only if it appears in an uninitialized variable or memory location.

### Scope

Scope refers to the visibility and accessibility of variables within different parts of a program. It determines where in your code a particular variable can be used or modified.

Key points about scope:

1. Types of Scope:
   - Global Scope: Variables declared outside all functions
   - Local Scope: Variables declared inside a function
   - Block Scope: Variables declared inside a block (e.g., within loops or conditional statements)

2. Lifetime: The scope of a variable also determines its lifetime - how long it exists in memory.

3. Variable Shadowing: When a local variable has the same name as a global variable, it "shadows" the global variable within its scope.

### Passing by Value (copy of value)
- Passing by value is a method of passing arguments to a function where a copy of the variable's value is passed, rather than a reference to the variable itself.
- Key points about passing by value:

1. Creation: When an argument is passed by value, a copy of the argument is created and passed to the function.
2. Original Unchanged: Changes made to the parameter inside the function do not affect the original variable in the calling code.
3. Memory Usage: Each parameter passed by value requires additional memory to store the copy.
Default in C: In C, all arguments are passed by value by default.

- In the example, num is passed by value to modifyValue(). The function modifies its local copy of the value, but the original num in main() remains unchanged.

### Overflow

Overflow is a condition that occurs when an arithmetic operation attempts to create a numeric value that is outside of the range that can be represented with a given number of digits – either higher than the maximum or lower than the minimum representable value.

Key points about overflow:

1. Types of Overflow:
   - Integer Overflow: Occurs with integer types
   - Floating-Point Overflow: Occurs with floating-point types

2. Unsigned Integer Overflow:
   - When the result exceeds the maximum value, it "wraps around" to the minimum value
   - In C, this behavior is well-defined

3. Signed Integer Overflow:
   - Leads to undefined behavior in C
   - Can result in unexpected values or program crashes

4. Floating-Point Overflow:
   - Results in special values like "infinity" or "NaN" (Not a Number)

5. Underflow:
   - The opposite of overflow, occurs when a value is too small to be represented
   - For floating-point types, can result in "subnormal" numbers or zero

6. Security Implications:
   - Can be exploited in buffer overflow attacks
   - May lead to logical errors in calculations
### Prevention:
- Use appropriate data types for the expected range of values
- Check for potential overflow before performing operations
- Use libraries or built-in functions that handle large numbers
- In critical applications, use overflow-checking compiler options or safe integer libraries

### File I/O (Input/Output)
File I/O refers to the process of reading from and writing to files in a program. It allows programs to store and retrieve data persistently. Here's an overview of key concepts related to file I/O:
1. Basic Operations:

   - Open a File: To perform I/O operations, you first need to open a file. This can be done in various modes (e.g., read, write, append).
   - Read from a File: Once a file is opened, you can read its contents using various methods (e.g., reading line by line or reading the entire file at once).
   - Write to a File: You can write data to a file, either by overwriting its existing content or appending new data to the end.
   - Close a File: After performing the necessary operations, the file should be closed to release system resources and ensure data is properly saved.

2. File Modes:

   - Read (r): Open an existing file for reading. The file must exist, and an error occurs if it does not.
   - Write (w): Open a file for writing. If the file does not exist, it is created. If the file exists, its content is truncated (i.e., erased).
   - Append (a): Open a file for writing. If the file does not exist, it is created. If the file exists, new data is added at the end.
   - Read/Write (r+): Open a file for both reading and writing. The file must exist, and an error occurs if it does not.
   - Binary Modes (b): Used in conjunction with other modes to open the file in binary mode (e.g., rb, wb). This is useful for non-text files (e.g., images, executables).

3. File Handling in C:

   - Opening a File: Use fopen(), which returns a FILE* pointer to the file. Example: FILE *file = fopen("example.txt", "r");
   - Reading from a File: Functions include fgetc(), fgets(), and fread().
   - Writing to a File: Functions include fputc(), fputs(), and fwrite().
   - Closing a File: Use fclose(). Example: fclose(file);

4. Error Handling:

   - Check the return values of file operations. For example, fopen() returns NULL if the file cannot be opened.
   - Use ferror() to check for errors during file operations and clearerr() to reset the error indicator.

5. Buffering:

   - File I/O operations may be buffered for efficiency. This means that data is temporarily stored in memory before being written to or read from a file.
   - You can manually flush the buffer using fflush(), ensuring that all data is written to the file.

6. File I/O in Other Languages:

   - Python: Uses built-in functions such as open(), read(), write(), and close(). Example: with open('example.txt', 'r') as file: content = file.read()
   - Java: Uses classes like FileReader, FileWriter, BufferedReader, and BufferedWriter. Example: BufferedReader reader = new BufferedReader(new FileReader("example.txt"));
   - C++: Uses file stream classes such as ifstream, ofstream, and fstream. Example: std::ifstream file("example.txt");

7. Security Considerations:

   - Validate File Paths: Ensure that file paths are validated to prevent directory traversal attacks.
   - Permissions: Set appropriate file permissions to control access to files.
   - Sanitize Input: Be cautious of file names or paths obtained from user input to prevent security vulnerabilities.

### Heap

The heap is a data structure that operates in a more complex manner compared to the stack. It follows a dynamic memory allocation model and can grow and shrink in size as needed.

Characteristics:
- Structure: The heap operates based on the principle of dynamic memory allocation. Elements are added and removed dynamically as the program requires.
- Memory Allocation: The heap is managed manually or semi-automatically, often using garbage collection for automatic memory management.
- Size Limit: The heap is typically larger and more flexible than the stack. It can accommodate a variable amount of memory depending on system limitations.
- Access Time: Accessing heap memory can be slower compared to stack memory due to its complexity and the overhead of dynamic allocation.

Usage:
- Dynamic Memory Allocation: The heap is commonly used for allocating memory at runtime. This allows for creating complex data structures with a size determined at runtime, such as linked lists, trees, or arrays.

Pros and Cons:

Pros:
- Flexible Size: The heap provides a flexible size, allowing for the allocation of memory based on the program's needs. It eliminates the need for a fixed size limit.
- Suitable for Large or Dynamic Data Structures: The heap is well-suited for creating large or dynamic data structures where the size is not known at compile time.

Cons:
- Slower Access: Accessing heap memory can be slower compared to stack memory due to the complexity of dynamic memory allocation and the overhead of managing memory.
- Requires Explicit Management: It is important to manage heap memory explicitly to prevent memory leaks and fragmentation, which can lead to performance issues.

### Stack
The stack is a data structure that follows the Last In, First Out (LIFO) principle. It operates based on the principle of Last In, First Out, where the most recently added item is the first to be removed.

Characteristics:
- Structure: The stack operates in a Last In, First Out (LIFO) manner.
- Memory Allocation: Stack memory is used for static memory allocation. It automatically handles allocation and deallocation of memory.
- Size Limit: The size of the stack is usually smaller and limited compared to the heap.
- Access Time: Access to stack memory is generally faster due to its simple structure and the fact that memory is managed by the system automatically.

Usage:
- Function Calls: Each function call creates a stack frame that includes local variables, function parameters, and return addresses.
- Local Variables: Variables declared inside functions or blocks are typically stored in stack memory.

Pros and Cons:
Pros:
- Fast access
- Automatic memory management

Cons:
- Limited size: Stack overflow can occur if the stack grows too large (e.g., deep recursion).
- Fixed size: The stack is less flexible for dynamic data.

## Stack vs Heap

**Lifetime:**
- Stack: Memory is allocated and deallocated automatically when functions or blocks are entered or exited.
- Heap: Memory remains allocated until explicitly deallocated or garbage collected.

**Scope:**
- Stack: Local to function or block.
- Heap: Accessible globally as long as you maintain a reference to the allocated memory.

**Memory Management:**
- Stack: Managed automatically.
- Heap: Requires manual management (in C/C++) or relies on garbage collection (in languages like Python, Java).

**Security Considerations:**
- Stack:
    - Stack Overflow: Can lead to crashes or vulnerabilities if not properly managed (e.g., buffer overflows).
- Heap:
    - Memory Leaks: Can occur if dynamically allocated memory is not properly freed, leading to resource exhaustion.
    - Dangling Pointers: Can occur if memory is freed but still accessed.

### Summary

Understanding the differences between stack and heap memory is crucial for effective programming, debugging, and optimizing code. The stack is best suited for fixed-size data with automatic management, while the heap is ideal for dynamic, large-scale data with manual memory management.
