
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