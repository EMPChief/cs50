# Time # Algorithms and Data Structures

## Time Complexity - Big O Notation

Time complexity measures how an algorithm's runtime grows relative to input size. Big O notation classifies algorithms based on their runtime or space requirements as input size increases.

### Notations
- **Big O (O)**: Upper bound or worst-case scenario
- **Big Omega (Ω)**: Lower bound or best-case scenario
- **Theta (Θ)**: Both upper and lower bounds (tight bound)

### Common Time Complexities

1. **Constant Time - O(1)**
   - Definition: Runtime is constant, independent of input size
   - Example: Accessing an array element by index
   - Bounds: O(1) and Ω(1)

2. **Logarithmic Time - O(log n)**
   - Definition: Runtime increases logarithmically with input size
   - Example: Binary search in a sorted array
   - Bounds: Typically O(log n) and Ω(log n)

3. **Linear Time - O(n)**
   - Definition: Runtime increases linearly with input size
   - Example: Iterating through an array
   - Bounds: O(n), potentially O(n^2) in complex cases

4. **Linearithmic Time - O(n log n)**
   - Definition: Runtime increases in proportion to n log n
   - Example: Efficient sorting algorithms (mergesort, heapsort)
   - Bounds: Often O(n log n), some operations Ω(log n)

5. **Quadratic Time - O(n^2)**
   - Definition: Runtime increases quadratically with input size
   - Example: Simple sorting algorithms (bubble sort, insertion sort)
   - Upper Bound: Sometimes O(n^3) for more complex cases

6. **Cubic Time - O(n^3)**
   - Definition: Runtime increases cubically with input size
   - Example: Algorithms with three nested loops
   - Bounds: Can be upper bounded by more complex time complexities

7. **Factorial Time - O(n!)**
   - Definition: Runtime increases factorially with input size
   - Example: Brute force solution for traveling salesman problem
   - Bounds: Typically the highest time complexity encountered

### Summary
--------
O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(n^3) < O(n!)
* O(1): Constant time, fastest, independent of input size.
* O(log n): Logarithmic time, very efficient for large datasets.
* O(n): Linear time, grows proportionally with input size.
* O(n log n): Linearithmic time, efficient for many complex algorithms like sorting.
* O(n^2): Quadratic time, less efficient, often seen in simpler algorithms.
* O(n^3): Cubic time, even less efficient, seen in more complex operations.
* O(n!): Factorial time, extremely inefficient, typically an upper bound for exhaustive search algorithms.


# Data Structures
## 1. Typedef and Structures in C
### Typedef
- The typedef keyword in C is used to create an alias for an existing data type. This is particularly useful when defining complex structures or when you want to simplify type declarations.
### Syntax:
```c
typedef existing_type new_alias;
### Bubble Sort
Bubble sort works by repeatedly swapping adjacent elements if they are in the wrong order. It continues this process until the array is sorted.

```python
def bubble_sort(numbers):
    n = len(numbers)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
                swapped = True
        if not swapped:
            break
    return numbers
};
```
### Using Typedef with Structures:
```c
typedef struct {
    char name[50];
    int age;
    float height;
} Person;
```
### Example:
```c
Person person1;
strcpy(person1.name, "Alice");
person1.age = 30;
person1.height = 5.5;
```
## 2. Arrays
### Definition
- An array is a collection of elements of the same data type, stored at contiguous memory locations. Arrays are useful for storing and accessing multiple values of the same type using a single variable name.
### Syntax
```c
data_type array_name[array_size];
```
### Example
```c
int numbers[5] = {1, 2, 3, 4, 5};
```
### Accessing Elements
- Array elements can be accessed using their index, with the first element having an index of 0.
### Example:
```c
int firstNumber = numbers[0]; // Access the first element
numbers[2] = 10; // Change the third element to 10
```
### Multi-dimensional Arrays
- Arrays can have more than one dimension. The most common are 2D arrays.

### Syntax:
```c
data_type array_name[size1][size2];
```
### Example:
```c
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```
### Arrays in Functions
- Arrays can be passed to functions, either by passing the array's name (which acts as a pointer) or explicitly specifying it in the parameter list.

### Function Declaration:
```c
void printArray(int arr[], int size);
```
### Example:
```c
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
```
### Key Concepts
- Contiguous Memory Allocation: Arrays allocate memory in a contiguous block, allowing efficient access via indexing.
- Fixed Size: The size of an array is defined at the time of declaration and cannot be altered during runtime.
- Homogeneous Elements: All elements in an array must be of the same type.

# Sorting

### To sort unsorted numbers 9 3 7 6 1 4 8 2 5 to get 1 2 3 4 5 6 7 8 9, we can use these types:

### Bubble Sort: (O(n^2))
- Repeatedly swap adjacent elements if they are in the wrong order.
- Example: Compare 9 and 3, swap. Compare 9 and 7, swap. Continue until the end. Repeat until the array is sorted.

### Insertion Sort: (O(n^2))
- Build the sorted array one element at a time by repeatedly inserting the next element into its correct position in the already sorted part of the array.
- Example: Start with 9. Insert 3 before 9. Insert 7 in the correct position. Continue until all elements are sorted.

### Selection Sort: (O(n^2))
- Repeatedly find the smallest element from the unsorted part and move it to the beginning.
- Example: Find the smallest element (1), move it to the front. Find the next smallest element (2), move it next. Continue until all elements are sorted.

### Merge Sort: (O(n log n))
- Divide the array into two halves, sort each half, and merge them back together.
- Example: Split into [9, 3, 7, 6] and [1, 4, 8, 2, 5]. Recursively split and sort each half, then merge them together.

### Heap Sort: (O(n log n))
- Rearrange the array to form a heap, and repeatedly remove the largest element from the heap and place it at the end.
- Example: Build a max heap from the array, remove the root (largest), place it at the end, and heapify the remaining elements. Repeat until sorted.

### Quick Sort: (O(n log n) on average, O(n^2) in worst case)
- Select a pivot element, partition the array around the pivot, and recursively sort the subarrays.
- Example: Choose 5 as pivot. Partition into [3, 1, 4, 2] and [7, 6, 8, 9]. Recursively sort the partitions.

### Shell Sort: (O(n log n) to O(n^2), depending on gap sequence)
- Divide the array into smaller subarrays using a gap sequence, sort each subarray, and then merge them back together.
- Example: Use gap sequence like [4, 2, 1]. Sort elements that are 4 positions apart, then 2 positions apart, then adjacent.

### Radix Sort: (O(d*(n+k)) where d is the number of digits and k is the range of digits)
- Sort based on individual digits or bits, starting from the least significant digit.
- Example: Sort by the least significant digit, then the next least significant, and so on until sorted.

### Bucket Sort: (O(n+k) average case, O(n^2) worst case)
- Distribute elements into buckets, sort each bucket individually, and then concatenate them.
- Example: Distribute elements into buckets like [1, 2], [3, 4], [5, 6], [7, 8], [9]. Sort and concatenate the buckets.

### Counting Sort: (O(n+k) where k is the range of the input)
- Count the number of occurrences of each unique element, and then place them in the correct order based on counts.
- Example: Count occurrences: 1 (1), 2 (1), 3 (1), ..., 9 (1). Place elements based on counts.
### Example Code: Merge Sort
```c
if only one number
    quit
else:
    sort left half of numbers
    sort right half of numbers
    Merge sorted halves
```
### Example Code: Merge Sort
```c
if only one number
    quit
else:
    sort left half of numbers
    sort right half of numbers
    Merge sorted halves
```
### Example Code: select sort
```c
for i from  0 to n-1
    find smallest number between numbers[i] and numbers[n-1]
    swap smallest number with numbers[i]
```
### Example Code: bubble sort
```c
repeat n-1 times
    for i from 0 to n-2
        if numbers[i] and numbers[i+1] are in wrong order
            swap numbers[i] and numbers[i+1]
```
### Example Code: bubble sort
```c
repeat n-1 times
    for i from 0 to n-2
        if numbers[i] and numbers[i+1] are in wrong order
            swap numbers[i] and numbers[i+1]
        if no swap occurs, the array is sorted
            quit the loop
```
### Example Code: Merge Sort
```c
if no doors left
    return false
if number behind middle door
    return true
else if number < middle door
    search left half
else if number > middle door
    search right half
```
```c
pick up a phone book
open in the middle of the phone book
look at page
if person is on the page
    call the person
else if person is earlier in the book
    search left half of the book
else if person is later in the book
    search right half of the book
else
    quit the program
```
