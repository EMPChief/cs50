# Time Complexity - Big O Notation
====================================================

- Time complexity is a measure of the amount of time an algorithm takes to process as a function of the length of the input. Big O notation is used to classify algorithms based on how their run time or space requirements grow as the input size grows.
- Ω is used to indicate an upper bound. O is used to indicate an lower bound. Ω is used to indicate an upper bound, and O is used to indicate an lower bound.

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

typedef struct - let us define our own data structures in C using the typedef keyword.
array - an array is a data structure that stores a collection of elements of the same data type, such as int, float, or string.

# Sorting
### if want to sort unsorted number 9 3 7 6 1 4 8 2 5 to get 1 2 3 4 5 6 7 8 9 i can use these type:
### Bubble Sort:
- Repeatedly swap adjacent elements if they are in the wrong order.
- Example: Compare 9 and 3, swap. Compare 9 and 7, swap. Continue until the end. Repeat until the array is sorted.
### Insertion Sort:
- Build the sorted array one element at a time by repeatedly inserting the next element into its correct position in the already sorted part of the array.
- Example: Start with 9. Insert 3 before 9. Insert 7 in the correct position. Continue until all elements are sorted.
### Selection Sort:
- Repeatedly find the smallest element from the unsorted part and move it to the beginning.
- Example: Find the smallest element (1), move it to the front. Find the next smallest element (2), move it next. Continue until all elements are sorted.
### Merge Sort:
- Divide the array into two halves, sort each half, and merge them back together.
- Example: Split into [9, 3, 7, 6] and [1, 4, 8, 2, 5]. Recursively split and sort each half, then merge them together.
### Heap Sort:
- Rearrange the array to form a heap, and repeatedly remove the largest element from the heap and place it at the end.
- Example: Build a max heap from the array, remove the root (largest), place it at the end, and heapify the remaining elements. Repeat until sorted.
### Quick Sort:
- Select a pivot element, partition the array around the pivot, and recursively sort the subarrays.
- Example: Choose 5 as pivot. Partition into [3, 1, 4, 2] and [7, 6, 8, 9]. Recursively sort the partitions.
### Shell Sort:
- Divide the array into smaller subarrays using a gap sequence, sort each subarray, and then merge them back together.
- Example: Use gap sequence like [4, 2, 1]. Sort elements that are 4 positions apart, then 2 positions apart, then adjacent.
### Radix Sort:
- Sort based on individual digits or bits, starting from the least significant digit.
- Example: Sort by the least significant digit, then the next least significant, and so on until sorted.
### Bucket Sort:
- Distribute elements into buckets, sort each bucket individually, and then concatenate them.
- Example: Distribute elements into buckets like [1, 2], [3, 4], [5, 6], [7, 8], [9]. Sort and concatenate the buckets.
### Counting Sort:
- Count the number of occurrences of each unique element, and then place them in the correct order based on counts.
- Example: Count occurrences: 1 (1), 2 (1), 3 (1), ..., 9 (1). Place elements based on counts.

