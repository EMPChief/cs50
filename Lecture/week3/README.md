# Week 3: Algorithms and Data Structures

This document provides a comprehensive overview of Week 3 topics in CS50, covering algorithms, data structures, and complexity analysis.

## Table of Contents
1. [Time Complexity and Big O Notation](#time-complexity-and-big-o-notation)
2. [Searching Algorithms](#searching-algorithms)
3. [Data Structures](#data-structures)
4. [Sorting Algorithms](#sorting-algorithms)
5. [Code Examples](#code-examples)

## Time Complexity and Big O Notation

Time complexity measures how an algorithm's runtime grows relative to its input size. We use Big O notation to classify algorithms based on their efficiency.

### Common Time Complexities

#### O(1) - Constant Time
- Runtime is independent of input size
- Example: Accessing an array element by index
- Best possible time complexity

#### O(log n) - Logarithmic Time
- Runtime grows logarithmically with input size
- Example: Binary search
- Very efficient for large datasets

#### O(n) - Linear Time
- Runtime grows linearly with input size
- Example: Linear search
- Common in single-pass algorithms

#### O(n log n) - Linearithmic Time
- Common in efficient sorting algorithms
- Examples: Merge sort, Heap sort
- Best possible time for comparison-based sorting

#### O(n²) - Quadratic Time
- Runtime grows quadratically with input size
- Examples: Bubble sort, Selection sort
- Generally inefficient for large datasets

#### O(n³) - Cubic Time
- Runtime grows cubically with input size
- Example: Simple matrix multiplication
- Usually indicates need for optimization

#### O(n!) - Factorial Time
- Runtime grows factorially with input size
- Example: Brute force traveling salesman
- Practically unusable for large inputs

## Searching Algorithms

### Linear Search
```c
// Implementation from Linear.c
int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == 0)
        {
            printf("Found at index %i\n", i);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

### Binary Search
- Requires sorted array
- Divides search interval in half each time
- O(log n) time complexity

## Data Structures

### Arrays
- Contiguous memory allocation
- Fixed size
- O(1) access time
- Example usage:
```c
int numbers[] = {1, 2, 3, 4, 5};
```

### Structures
Example from our phonebook implementation:
```c
typedef struct
{
    string name;
    string number;
} person;

// Usage
person people[2];
people[0].name = "Carter";
people[0].number = "+1-617-495-1000";
```

### Linked Lists
- Dynamic size
- Non-contiguous memory
- O(n) access time
- Example implementation covered in later weeks

## Sorting Algorithms

### Bubble Sort
- O(n²) time complexity
- Simple implementation
- Good for small datasets

### Selection Sort
- O(n²) time complexity
- Minimizes number of swaps
- In-place sorting

### Merge Sort
- O(n log n) time complexity
- Divide and conquer approach
- Requires extra space

## Code Examples

### Phonebook Implementation
```c
// From Phonebook_w_struct_typedf.c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

### Tries Data Structure
Tries are tree-like data structures commonly used for storing strings, particularly useful for implementing dictionaries and autocomplete features. The implementation can be found in `tries.c`.

## Practice Problems

1. Implement binary search for a sorted array of integers
2. Create a phone book using different data structures (arrays vs. structs)
3. Compare the performance of different sorting algorithms
4. Analyze the time complexity of given code snippets

## Additional Resources

- [CS50 Study Materials](https://cs50.harvard.edu/x/2024/notes/3/)
- [Visualization of Sorting Algorithms](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)
- [Big O Cheat Sheet](https://www.bigocheatsheet.com/) 