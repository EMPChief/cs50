Time Complexity - Big O Notation
====================================================

Time complexity is a measure of the amount of time an algorithm takes to process as a function of the length of the input. Big O notation is used to classify algorithms based on how their run time or space requirements grow as the input size grows.
Ω is used to indicate an upper bound. O is used to indicate an lower bound. Ω is used to indicate an upper bound, and O is used to indicate an lower bound.

### Constant Time Complexity - O(1) - Ω(1)

* Definition: The time taken by the algorithm is constant and does not depend on the size of the input.
* Example: Accessing an element in an array by its index.
* Bounds: O(1) is both an upper and lower bound, indicating the fastest possible time complexity.

### Logarithmic Time Complexity - O(log n) - Ω(log n)

* Definition: The time taken by the algorithm increases logarithmically as the input size increases.
* Example: Binary search in a sorted array.
* Bounds: O(log n) is typically both an upper and lower bound for algorithms like binary search, making it efficient for large datasets.

### Linear Time Complexity - O(n) - Ω(n)

* Definition: The time taken by the algorithm increases linearly with the input size.
* Example: Iterating through an array.
* Upper Bound: Algorithms with linear complexity can also have O(n^2) as an upper bound in more complex cases, meaning in the worst case, they may perform worse.

### Linearithmic Time Complexity - O(n log n) - Ω(n log n)

* Definition: The time taken by the algorithm increases in proportion to n log n.
* Example: Efficient sorting algorithms like mergesort and heapsort.
* Bounds: O(n log n) is often an upper bound for comparison-based sorting algorithms. Some simpler operations within these algorithms may have O(log n) as a lower bound.

### Quadratic Time Complexity - O(n^2) - Ω(n^2)

* Definition: The time taken by the algorithm increases quadratically as the input size increases.
* Example: Simple sorting algorithms like bubble sort, insertion sort, and selection sort.
* Upper Bound: O(n^3) is often cited as an upper bound for more complex algorithms, indicating that the algorithm can be even slower in the worst case.

### Cubic Time Complexity - O(n^3) - Ω(n^3)

* Definition: The time taken by the algorithm increases cubically with the input size.
* Example: Algorithms involving three nested loops, such as certain dynamic programming solutions.
* Bounds: Generally, these are slower and less efficient for large inputs but can be upper bounded by more complex time complexities.

### Factorial Time Complexity - O(n!) - Ω(n!)

* Definition: The time taken by the algorithm increases factorially with the input size.
* Example: Solving the traveling salesman problem using brute force.
* Bounds: This is an upper bound indicating extremely inefficient algorithms for large inputs, with O(n!) typically being the highest time complexity encountered in algorithms.

Summary
--------

* O(1): Constant time, fastest, independent of input size.
* O(log n): Logarithmic time, very efficient for large datasets.
* O(n): Linear time, grows proportionally with input size.
* O(n log n): Linearithmic time, efficient for many complex algorithms like sorting.
* O(n^2): Quadratic time, less efficient, often seen in simpler algorithms.
* O(n^3): Cubic time, even less efficient, seen in more complex operations.
* O(n!): Factorial time, extremely inefficient, typically an upper bound for exhaustive search algorithms.


### Data Structures

typedef struct - let us define our own data structures in C using the typedef keyword.
array - an array is a data structure that stores a collection of elements of the same data type, such as int, float, or string.


## Example Code: Linear Search Algorithm with int array
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int number = get_int("Enter a number: ");
    for (int i = 0; i < 5; i++)
    {
        if (numbers[i] == number)
        {
            printf("Number %d found in the array!\n", number);
            return 0;
        }
    }
    printf("Number %d not found in the array.\n", number);
    return 1;
}
```
### Example Code: Linear Search Algorithm with string array
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string stringlist[] = {"apple", "banana", "cherry", "date", "elderberry"};

    string search = get_string("Search: ");
    for (int i = 0; i < 5; i++)
    {
        // strcmp() returns 0 if the strings are equal and -1 if the first string is less than the second. 
        if (strcmp(stringlist[i], search) == 0)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}
```
### Example Code: Phonebook with string array
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Phonebook
    string phonebookname[] = {"John Doe", "Jane Doe", "John Smith", "Jane Smith"};
    string phonebooknumber[] = {"+47-123-456-7890", "+47-123-456-7891", "+47-123-456-7892", "+47-123-456-7893"};

    // Get user's input for name
    string name = get_string("Name: ");
    
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, phonebookname[i]) == 0)
        {
            printf("Number: %s\n", phonebooknumber[i]);
            return 0;
        }
    }
    printf("No such person.\n");

    return 1;
}
```
### Example Code: Phonebook with struct array 
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} phonebook;

int main(void)
{
    // Phonebook
    phonebook phonebookname[4] = {
        {"Alice", "111-111-1111"},
        {"Bob", "222-222-2222"},
        {"Charlie", "333-333-3333"},
        {"David", "444-444-4444"}
    };

    // Get user's input for name
    string name = get_string("Name: ");

    // Search for the name in the phonebook
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, phonebookname[i].name) == 0)
        {
            printf("Number: %s\n", phonebookname[i].number);
            return 0;
        }
    }

    // If the name was not found
    printf("No such person.\n");
    return 1;
}
```
### Example Code: Phonebook with struct array with typedef
```c
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char number[15];
} phonebook;

int main(void)
{
    // Phonebook
    phonebook phonebookname[4] = {
        {"Alice", "111-111-1111"},
        {"Bob", "222-222-2222"},
        {"Charlie", "333-333-3333"},
        {"David", "444-444-4444"}
    };

    // Get user's input for name
    char name[50];
    printf("Name: ");
    if (fgets(name, sizeof(name), stdin) != NULL)
    {
        // Remove newline character from the end of the input if present
        name[strcspn(name, "\n")] = 0;
    }

    // Search for the name in the phonebook
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, phonebookname[i].name) == 0)
        {
            printf("Number: %s\n", phonebookname[i].number);
            return 0;
        }
    }

    // If the name was not found
    printf("No such person.\n");
    return 1;
}
```
### Example Code: Phonebook with struct array with typedef
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} phonebook;

int main(void)
{
    // Phonebook
    phonebook phonebookname[4];

    phonebookname[0].name = "Alice";
    phonebookname[0].number = "123-4567";
    phonebookname[1].name = "Bob";
    phonebookname[1].number = "234-5678";
    phonebookname[2].name = "Charlie";
    phonebookname[2].number = "345-6789";
    phonebookname[3].name = "David";
    phonebookname[3].number = "456-7890";

    // Get user's input for name
    string name = get_string("Name: ");

    // Search for the name in the phonebook
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, phonebookname[i].name) == 0)
        {
            printf("Number: %s\n", phonebookname[i].number);
            return 0;
        }
    }

    // If the name was not found
    printf("No such person.\n");
    return 1;
}
```