# Time Complexity - Big O Notation
====================================================

- Time complexity is a measure of the amount of time an algorithm takes to process as a function of the length of the input. Big O notation is used to classify algorithms based on how their run time or space requirements grow as the input size grows.
### Big O, Big Omega, and Theta Notations
- Big O notation (O) represents the upper bound or worst-case scenario of the time complexity of an algorithm.
- Big Omega notation (Ω) represents the lower bound or best-case scenario of the time complexity of an algorithm.
- Theta notation (Θ) represents both the upper and lower bounds, essentially providing a tight bound on the time complexity of an algorithm.

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


# Data Structures
## 1. Typedef and Structures in C
### Typedef
- The typedef keyword in C is used to create an alias for an existing data type. This is particularly useful when defining complex structures or when you want to simplify type declarations.
### Syntax:
```c
typedef existing_type new_alias;
```
### Example:
```c
typedef unsigned long ulong;
ulong myVar; // myVar is now an alias for unsigned long
```
### Structures
- Structures (struct) in C allow you to group different types of variables under a single name. This is particularly useful for representing real-world entities that have multiple attributes.

### Defining a Structure:
```c
struct Person {
    char name[50];
    int age;
    float height;
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
### if want to sort unsorted number 9 3 7 6 1 4 8 2 5 to get 1 2 3 4 5 6 7 8 9 i can use these type:
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
### Quick Sort: (O(n log n)) on average, O(n^2) on worst case
- Select a pivot element, partition the array around the pivot, and recursively sort the subarrays.
- Example: Choose 5 as pivot. Partition into [3, 1, 4, 2] and [7, 6, 8, 9]. Recursively sort the partitions.
### Shell Sort: (O(n log2 n))
- Divide the array into smaller subarrays using a gap sequence, sort each subarray, and then merge them back together.
- Example: Use gap sequence like [4, 2, 1]. Sort elements that are 4 positions apart, then 2 positions apart, then adjacent.
### Radix Sort: (O(nk)) where k is the number of digits
- Sort based on individual digits or bits, starting from the least significant digit.
- Example: Sort by the least significant digit, then the next least significant, and so on until sorted.
### Bucket Sort: (O(n+k)) where k is the number of buckets
- Distribute elements into buckets, sort each bucket individually, and then concatenate them.
- Example: Distribute elements into buckets like [1, 2], [3, 4], [5, 6], [7, 8], [9]. Sort and concatenate the buckets.
### Counting Sort: (O(n+k)) where k is the range of the input
- Count the number of occurrences of each unique element, and then place them in the correct order based on counts.
- Example: Count occurrences: 1 (1), 2 (1), 3 (1), ..., 9 (1). Place elements based on counts.

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
