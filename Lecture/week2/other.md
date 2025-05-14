# Week 2: Arrays, Strings, and Command-Line Arguments

This document contains examples and explanations of key concepts covered in Week 2 of CS50.

## Table of Contents
1. [String Length Implementation](#string-length-implementation)
2. [String Manipulation](#string-manipulation)
3. [Character Case Conversion](#character-case-conversion)
4. [Command Line Arguments](#command-line-arguments)
5. [ASCII Art Example](#ascii-art-example)
6. [Sample Program Output](#sample-program-output)

## String Length Implementation
Here's a custom implementation of string length calculation:

```c
#include <stdio.h>
#include "cs50.h"

int string_length(string s);

int main(void)
{
    string name = get_string("What's your name? ");
    int length = string_length(name);
    printf("Length: %i\n", length);
}

int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
```

This example demonstrates:
- Custom function implementation
- String traversal
- Null terminator concept

## String Manipulation
Example of basic string handling:

```c
#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: %s\n", s);
    // Print character by character
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}
```

## Character Case Conversion
Two approaches to converting lowercase to uppercase:

### Manual Conversion
```c
#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);  // Convert to uppercase using ASCII math
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```

### Using ctype.h
```c
#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));  // Using the built-in toupper function
    }
    printf("\n");
}
```

## Command Line Arguments
Basic example of handling command-line arguments:

```c
#include <stdio.h>
#include "cs50.h"

int main(int argc, string argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Hello, %s\n", argv[i]);
    }
}
```

## ASCII Art Example
Here's a fun example that combines command-line arguments with ASCII art:

```c
#include <stdio.h>
#include "cs50.h"

int main(int argc, string argv[])
{
    // Print arguments first
    for (int i = 1; i < argc; i++)
    {
        printf("Hello, %s\n", argv[i]);
    }

    // Print a cute ASCII art
    printf("\n");
    printf("        *****        \n");
    printf("    ***       ***    \n");
    printf("  **             **  \n");
    printf(" **   \\  O O  /   ** \n");
    printf("**     \\  ^  /     **\n");
    printf("**     |     |     **\n");
    printf("**     |     |     **\n");
    printf(" **    \\___/    **  \n");
    printf("  **           **   \n");
    printf("    ***     ***     \n");
    printf("        *****       \n");
    printf("\n");

    return 0;
}
```

## Sample Program Output
Here are some example interactions with the programs:

### Scrabble Game
```bash
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!

$ ./scrabble
Player 1: red
Player 2: wheelbarrow
Player 2 wins!
```

### Readability Program
```bash
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3

$ ./readability
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 5
```