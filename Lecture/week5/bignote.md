# Usefull links:
- [Jack Learns the Facts About Queues and Stacks](https://www.youtube.com/watch?v=ItAG3s6KIEI)
- [CS50x 2024 - Lecture 5 - Data Structures](https://www.youtube.com/watch?v=0euvEdPwQnQ)
# Stacks & Queues
### Stacks and Queues are fundamental data structures in computer science, each with specific characteristics and use cases.
## Stack
- Last In, First Out (LIFO) principle
- Elements are added and removed from the same end (top)
- Main operations: push (add) and pop (remove)
## Queue
- First In, First Out (FIFO) principle
- Elements are added at one end (rear) and removed from the other end (front)
- Main operations: enqueue (add) and dequeue (remove)
### FIFO (First In, First Out)
### Characteristic of a Queue
- The first element added to the queue will be the first one to be removed
- Also known as "First Come, First Served"
- Gives more fairness than LIFO
### LIFO (Last In, First Out)
### Characteristic of a Stack
- The last element added to the stack will be the first one to be removed
- Also known as "Last In, First Out"
- Does not give same fairness as FIFO
## What would we use a Queue and dequeue for in a real-life scenario programming?
### Queue can be used to do things such as:
1. Print Spooler: Managing print jobs sent to a printer.
2. Task Scheduling: Managing processes in an operating system.
3. Breadth-First Search: In graph algorithms for traversing or searching tree or graph data structures.
4. Buffering: In streaming applications, like video streaming services.
5. Customer Service Systems: Managing customer support tickets.
# Resizing Array
### A resizing array is a data structure that can grow or shrink in size as needed. It combines the benefits of arrays (constant-time access to elements) with the flexibility of dynamic sizing.
## Array
- Fixed size, determined at creation
- Fast access to elements (O(1) time complexity)
- Efficient memory usage
- Limited flexibility due to fixed size
## Dynamic Array
- Resizable: can grow or shrink as needed
- O(1) average time complexity for element access
- Flexible usage: allows for more flexible usage compared to static arrays
- Typical implementation:
  - Start with an initial capacity
  - When the array is full, create a new array with larger capacity (often double)
  - Copy elements from the old array to the new one
  - Delete the old array
### Key Operations:
- Append: Add an element to the end (amortized O(1) time)
- Get/Set: Access or modify an element at a specific index (O(1) time)
- Insert: Add an element at a specific position (O(n) time in worst case)
- Delete: Remove an element (O(n) time in worst case)
- Resize: Increase or decrease capacity (O(n) time, but done infrequently)
### Advantages:
- Dynamic size adjustment
- Efficient for most operations
- No need to predict size in advance
### Disadvantages:
- Occasional performance hits during resizing
- May waste some memory due to over-allocation
### Common Implementations:
- ArrayList in Java
- List in Python
- vector in C++


# Linked list

# trees 

# Dictionaries

# Hashing and hash tables

# Tries

