Time Complexity - Big O Notation
====================================================

Time complexity is a measure of the amount of time an algorithm takes to process as a function of the length of the input. Big O notation is used to classify algorithms based on how their run time or space requirements grow as the input size grows.
Ω is used to indicate an upper bound. O is used to indicate an lower bound.

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

