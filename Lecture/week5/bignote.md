# Data Structures Notes

## Introduction

Data structures are fundamental building blocks of computer programs, enabling efficient storage, retrieval, and manipulation of data. Understanding various data structures is crucial for developing efficient algorithms and solving complex problems in computer science.

## Stacks & Queues

Stacks and queues are fundamental data structures in computer science, each with specific characteristics and use cases.

### Stack

- Last In, First Out (LIFO) principle
- Elements are added and removed from the same end (top)
- Main operations: push (add), pop (remove), peek (view top element without removing)
- Implementation: Can be implemented using arrays or linked lists

#### Use Cases:
- Implementing recursive algorithms iteratively
- Parsing expressions with nested parentheses
- Evaluating postfix notation
- Managing function calls in program execution
- Implementing undo/redo functionality in text editors
- Backtracking algorithms (e.g., solving mazes)
- Browser history management
- Syntax checking in compilers

#### Characteristics:
- Fast access to top element (O(1))
- Efficient insertion and deletion at one end
- Limited access to elements other than top

### Queue

- First In, First Out (FIFO) principle
- Elements are added at one end (rear) and removed from the other end (front)
- Main operations: enqueue (add), dequeue (remove), peek (view front element without removing)
- Implementation: Can be implemented using arrays or linked lists

#### Use Cases:
- Job scheduling in operating systems
- Print queues in printers
- Handling requests in web servers
- Breadth-First Search (BFS) algorithm
- Implementing chatbots or messaging systems
- Network protocols (e.g., TCP/IP)
- Job queues in distributed systems
- Load balancing in web servers

#### Characteristics:
- Fast access to front element (O(1))
- Efficient insertion at rear and deletion from front
- Limited access to elements other than front and rear

### FIFO (First In, First Out)

Characteristic of a queue:
- The first element added will be the first one removed
- Also known as "First Come, First Served"
- Provides fairness compared to LIFO
- Used in scenarios where order of arrival matters

### LIFO (Last In, First Out)

Characteristic of a stack:
- The last element added will be the first one removed
- Also known as "Last In, First Out"
- Does not provide the same fairness as FIFO
- Useful in scenarios where recent items are more important

## Resizing Arrays

Resizing arrays are data structures that can grow or shrink in size as needed, combining the benefits of arrays with dynamic sizing.

### Array

- Fixed size determined at creation
- Fast access to elements (O(1) time complexity)
- Efficient memory usage
- Limited flexibility due to fixed size

#### Use Cases:
- Storing a fixed number of items
- Representing matrices or images
- Caching frequently accessed data
- Implementing hash tables
- Creating lookup tables
- Managing fixed-size buffers

#### Characteristics:
- Fast random access
- Efficient memory usage for contiguous allocation
- Inflexible in terms of size changes

### Dynamic Array

- Resizable: can grow or shrink as needed
- O(1) average time complexity for element access
- Flexible usage compared to static arrays
- Typical implementation:
  - Start with initial capacity
  - When full, create a new array with larger capacity (often double)
  - Copy elements from old to new array
  - Delete old array

#### Use Cases:
- Implementing dynamic collections in languages
- Creating flexible buffers for network communication
- Building efficient caching systems
- Managing growing datasets in memory
- Implementing vectors in programming languages
- Dynamic memory allocation in operating systems

#### Characteristics:
- Flexible size adjustment
- Amortized constant-time operations
- Potential performance impact during resizing
- More memory overhead compared to static arrays

## Linked Lists

Linked lists are linear data structures where elements are stored in nodes, each containing data and a reference to the next node.

### Characteristics

- Dynamic size
- Efficient insertion and deletion
- Non-contiguous memory allocation
- Sequential access (not random access)

#### Use Cases:
- Implementing dynamic memory allocation
- Creating flexible database query result sets
- Managing browser history in web browsers
- Building efficient undo/redo functionality
- Implementing LRU (Least Recently Used) caches
- Dynamic memory management in operating systems
- Implementing garbage collection algorithms

#### Types:
1. Singly Linked List: Each node points to the next node
2. Doubly Linked List: Each node points to both next and previous nodes
3. Circular Linked List: Last node points back to the first node

#### Characteristics:
- Efficient insertion/deletion at arbitrary positions
- Slow random access compared to arrays
- More memory overhead due to pointers

## Trees

Trees are hierarchical data structures consisting of nodes connected by edges, forming a non-linear structure.

### Characteristics

- Root node (top of the tree)
- Parent and child relationships between nodes
- Leaves (nodes with no children)
- Subtrees (trees within the main tree)

#### Use Cases:
- File systems organization
- Database indexing
- XML/HTML document structure representation
- Social network analysis
- Compilers and interpreters
- Decision trees in machine learning
- Huffman coding for compression
- Efficient sorting algorithms

#### Common Types:
1. Binary Tree: Each node has at most two children
2. Binary Search Tree (BST): Ordered binary tree
3. AVL Tree: Self-balancing BST
4. Red-Black Tree: Self-balancing BST with color properties
5. B-Tree: Multiway search tree (commonly used in databases)

#### Characteristics:
- Efficient searching, insertion, and deletion operations
- Hierarchical representation of data
- Can be unbalanced, affecting performance

## Dictionaries

Dictionaries store key-value pairs, allowing efficient lookup, insertion, and deletion based on keys.

### Characteristics

- Keys are unique identifiers
- Values can be any type of data
- Fast average-case performance for operations

#### Use Cases:
- Configuration files parsing
- JSON/XML parsing
- Implementing caches
- Creating symbol tables in compilers
- Building efficient data storage systems
- Implementing sets and maps in programming languages
- Database indexing
- Web session management

#### Characteristics:
- Fast average-case lookup, insertion, and deletion
- Potential collisions affecting performance
- Flexible key-value pair storage

## Hashing and Hash Tables

Hashing maps keys to indices of an array, utilized in hash tables to efficiently store key-value pairs.

### Key Concepts

- Hash function: Maps keys to indices
- Collisions: When two keys hash to the same index
- Load factor: Ratio of occupied slots to total capacity

#### Use Cases:
- Implementing efficient caches
- Creating fast lookup tables
- Building bloom filters
- Optimizing database queries
- Implementing sets and maps in programming languages
- Password storage in authentication systems
- Load balancing in distributed systems

#### Characteristics:
- Fast average-case lookup, insertion, and deletion
- Potential collisions affecting performance
- Flexible key-value pair storage
- Requires careful hash function design

## Tries

Tries (prefix trees) are tree-like data structures used to store collections of strings efficiently.

### Characteristics

- Each node represents a string prefix
- Children represent extensions of the prefix
- Root node represents the empty string

#### Use Cases:
- Autocomplete features in search engines
- Spell checking and auto-correction
- IP routing tables management
- Validating input against a set of known strings
- Implementing efficient string matching algorithms
- Text indexing in search engines
- DNA sequencing analysis

#### Characteristics:
- Efficient prefix matching
- Ordered storage of strings
- Space efficiency for common prefixes
- Slower operations for very large datasets

#### Common Operations:
- Insertion: Add a new string to the trie
- Deletion: Remove a string from the trie
- Search: Find if a string exists in the trie
- Prefix search: Find all strings with a given prefix

#### Advantages:
- Fast retrieval of strings with common prefixes
- Space-efficient storage of large dictionaries
- Efficient autocomplete functionality

#### Disadvantages:
- Higher memory usage compared to hash tables
- Slower operations for very large datasets
- Complex implementation compared to simpler data structures

## Graphs

Graphs are non-linear data structures consisting of nodes connected by edges, representing relationships between entities.

### Characteristics

- Nodes (vertices): Represent entities
- Edges: Represent connections between nodes
- Directed vs Undirected graphs
- Weighted vs Unweighted graphs

#### Use Cases:
- Social network analysis
- Route planning algorithms
- Network topology representation
- Database schema design
- Compiler optimizations
- Recommendation systems
- Traffic simulation
- Molecular modeling

#### Types:
1. Directed Graph: Edges have direction
2. Undirected Graph: Edges do not have direction
3. Weighted Graph: Edges have weights or costs
4. Unweighted Graph: All edges have equal weight

#### Characteristics:
- Flexible representation of relationships
- Efficient traversal algorithms (DFS, BFS)
- Complex analysis for large graphs
- Various applications across domains

#### Common Operations:
- Traversal: Visiting nodes in a systematic order
- Shortest Path: Finding the minimum-weight path between nodes
- Minimum Spanning Tree: Finding the subset of edges connecting all nodes with minimum total weight
- Topological Sort: Ordering nodes based on dependencies

#### Advantages:
- Natural representation of many real-world problems
- Powerful algorithms for solving graph-related problems
- Flexibility in representing various types of relationships

#### Disadvantages:
- Higher memory requirements compared to linear structures
- Complex algorithms for some operations
- Potential for high time complexity in large graphs
