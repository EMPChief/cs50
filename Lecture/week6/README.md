# Week 6: Python Programming

This document provides a comprehensive overview of Week 6 topics in CS50, covering the transition from C to Python and introducing Python programming concepts.

## Table of Contents
1. [Introduction to Python](#introduction-to-python)
2. [Basic Syntax Comparison](#basic-syntax-comparison)
3. [Python Data Types](#python-data-types)
4. [Control Structures](#control-structures)
5. [Functions and Libraries](#functions-and-libraries)
6. [Code Examples](#code-examples)

## Introduction to Python

### Key Differences from C
- No explicit type declarations
- No memory management
- Indentation matters
- Rich standard library
- More built-in data structures

### Python Features
- Dynamic typing
- Interpreted language
- Extensive package ecosystem
- Focus on readability
- "Batteries included" philosophy

## Basic Syntax Comparison

### Hello World
C vs Python:
```c
// C version
#include <stdio.h>

int main(void)
{
    printf("Hello, world\n");
    return 0;
}
```

```python
# Python version
print("Hello, world")
```

### Getting User Input
```python
# From get_int.py
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")

# Usage
x = get_int("x: ")
print(f"x is {x}")
```

## Python Data Types

### Basic Types
```python
# Numbers
integer = 42
float_num = 3.14

# Strings
name = "CS50"
multiline = """
Multiple
lines
"""

# Boolean
is_true = True
is_false = False

# None
empty = None
```

### Collections
```python
# From dictionary.py
# Dictionary example
words = {
    "hello": "world",
    "goodbye": "moon"
}

# List example
numbers = [1, 2, 3, 4, 5]

# Tuple example
coordinates = (42.3601, -71.0589)
```

## Control Structures

### Conditionals
```python
# From agree.py
answer = input("Do you agree? ").lower()

if answer in ["y", "yes"]:
    print("Agreed.")
elif answer in ["n", "no"]:
    print("Not agreed.")
```

### Loops
```python
# From py_loop.py
# For loop
for i in range(3):
    print("meow")

# While loop
i = 0
while i < 3:
    print("meow")
    i += 1
```

## Functions and Libraries

### Function Definition
```python
def square(n):
    """Return the square of n."""
    return n * n

def main():
    x = get_int("x: ")
    print(f"x squared is {square(x)}")

if __name__ == "__main__":
    main()
```

### Calculator Example
```python
# From calculator.py
def main():
    x = get_int("x: ")
    y = get_int("y: ")
    
    print(f"x + y = {x + y}")
    print(f"x - y = {x - y}")
    print(f"x * y = {x * y}")
    print(f"x / y = {x / y}")
    print(f"x // y = {x // y}")  # Integer division
    print(f"x % y = {x % y}")    # Remainder
    print(f"x ** y = {x ** y}")  # Exponentiation

if __name__ == "__main__":
    main()
```

## Code Examples

### Simple Meow Program
```python
# From meow.py
def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

if __name__ == "__main__":
    main()
```

### Comparison
```python
# From compare.py
x = int(input("What's x? "))
y = int(input("What's y? "))

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

## Practice Problems

1. Convert C programs from previous weeks to Python
2. Implement a dictionary-based phone book
3. Create a simple text processing script
4. Build a command-line calculator with advanced features

## Python Best Practices

1. Follow PEP 8 style guide
2. Use meaningful variable names
3. Write docstrings for functions
4. Handle exceptions appropriately
5. Use list comprehensions when appropriate

## Common Pitfalls to Avoid

1. Forgetting that indentation matters
2. Mixing tabs and spaces
3. Not handling exceptions
4. Mutable default arguments
5. Forgetting to close files

## Additional Resources

- [CS50 Python Notes](https://cs50.harvard.edu/x/2024/notes/6/)
- [Python Documentation](https://docs.python.org/3/)
- [Python Package Index (PyPI)](https://pypi.org/)
- [PEP 8 Style Guide](https://pep8.org/) 