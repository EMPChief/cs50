# Usefull links:
- [Jack Learns the Facts About Queues and Stacks](https://www.youtube.com/watch?v=ItAG3s6KIEI)
- [CS50x 2024 - Lecture 5 - Data Structures](https://www.youtube.com/watch?v=0euvEdPwQnQ)
# Data Structures Notes

## Stacks & Queues

Stacks and queues are fundamental data structures in computer science, each with specific characteristics and use cases.

### Stack

- Last In, First Out (LIFO) principle
- Elements are added and removed from the same end (top)
- Main operations: push (add) and pop (remove)

### Queue

- First In, First Out (FIFO) principle
- Elements are added at one end (rear) and removed from the other end (front)
- Main operations: enqueue (add) and dequeue (remove)

### FIFO (First In, First Out)

Characteristic of a queue:
- The first element added will be the first one removed
- Also known as "First Come, First Served"
- Provides fairness compared to LIFO

### LIFO (Last In, First Out)

Characteristic of a stack:
- The last element added will be the first one removed
- Also known as "Last In, First Out"
- Does not provide the same fairness as FIFO

## Resizing Arrays

Resizing arrays are data structures that can grow or shrink in size as needed, combining the benefits of arrays with dynamic sizing.

### Array

- Fixed size determined at creation
- Fast access to elements (O(1) time complexity)
- Efficient memory usage
- Limited flexibility due to fixed size

### Dynamic Array

- Resizable: can grow or shrink as needed
- O(1) average time complexity for element access
- Flexible usage compared to static arrays
- Typical implementation:
  - Start with initial capacity
  - When full, create a new array with larger capacity (often double)
  - Copy elements from old to new array
  - Delete old array

## Linked Lists

Linked lists are linear data structures where elements are stored in nodes, each containing data and a reference to the next node.

### Characteristics

- Dynamic size
- Efficient insertion and deletion
- Non-contiguous memory allocation
- Sequential access (not random access)

### Common Operations

- Insertion: Add an element to the end of the list
- Deletion: Remove an element from the list
- Access: Retrieve an element from the list
- Traversal: Iterate through the list
- Search: Find an element in the list
- -> : Points to the next node

### Types

1. Singly Linked List: Each node points to the next node
2. Doubly Linked List: Each node points to both next and previous nodes
3. Circular Linked List: Last node points back to the first node

## Trees

Trees are hierarchical data structures consisting of nodes connected by edges, forming a non-linear structure.

### Characteristics

- Root node (top of the tree)
- Parent and child relationships between nodes
- Leaves (nodes with no children)
- Subtrees (trees within the main tree)

### Common Types

1. Binary Tree: Each node has at most two children
2. Binary Search Tree (BST): Ordered binary tree
3. AVL Tree: Self-balancing BST
4. Red-Black Tree: Self-balancing BST with color properties
5. B-Tree: Multiway search tree (commonly used in databases)

## Dictionaries

Dictionaries store key-value pairs, allowing efficient lookup, insertion, and deletion based on keys.

### Characteristics

- Keys are unique identifiers
- Values can be any type of data
- Fast average-case performance for operations

### Common Operations

- Insertion: Add a new key-value pair
- Deletion: Remove a key-value pair
- Lookup: Retrieve value associated with a given key

## Hashing and Hash Tables

Hashing maps keys to indices of an array, utilized in hash tables to efficiently store key-value pairs.

### Key Concepts

- Hash function: Maps keys to indices
- Collisions: When two keys hash to the same index
- Load factor: Ratio of occupied slots to total capacity

## Tries

Tries (prefix trees) are tree-like data structures used to store collections of strings efficiently.

### Characteristics

- Each node represents a string prefix
- Children represent extensions of the prefix
- Root node represents the empty string

### Common Operations

- Insertion: Add a new string to the trie
- Deletion: Remove a string from the trie
- Search: Find if a string exists in the trie
- Prefix search: Find all strings with a given prefix

### Advantages

- Efficient prefix matching
- Ordered storage of strings
- Space efficiency for common prefixes

### Disadvantages

- Higher memory usage compared to hash tables
- Slower operations for very large datasets

### Use Cases

- Autocomplete features
- Spell checking
- IP routing tables
- Validating input against a set of known strings
