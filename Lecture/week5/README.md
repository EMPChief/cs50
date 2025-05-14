# Week 5: Data Structures

This document provides a comprehensive overview of Week 5 topics in CS50, covering various data structures and their implementations in C.

## Table of Contents
1. [Linked Lists](#linked-lists)
2. [Hash Tables](#hash-tables)
3. [Trees](#trees)
4. [Queues](#queues)
5. [Implementation Examples](#implementation-examples)

## Linked Lists

### Basic Linked List Structure
```c
// From list.c
typedef struct node
{
    int number;
    struct node *next;
}
node;
```

### Operations
- Insertion
- Deletion
- Traversal
- Search

### Example Implementation
```c
// From lists.c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // Initialize list as empty
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // Add another number
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
```

## Hash Tables

### Basic Concepts
- Hash function
- Collision resolution
- Load factor
- Resizing

### Example Implementation
```c
// From simple_hash.c
typedef struct node
{
    char *name;
    char *number;
    struct node *next;
}
node;

// Hash table
node *table[26];

// Hash function
int hash(char *name)
{
    return toupper(name[0]) - 'A';
}

// Insert into hash table
bool insert(char *name, char *number)
{
    // Create new node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }
    
    // Copy strings
    n->name = strdup(name);
    if (n->name == NULL)
    {
        free(n);
        return false;
    }
    
    n->number = strdup(number);
    if (n->number == NULL)
    {
        free(n->name);
        free(n);
        return false;
    }
    
    // Hash name
    int index = hash(name);
    
    // Insert node
    n->next = table[index];
    table[index] = n;
    
    return true;
}
```

## Trees

### Binary Search Tree
```c
// From trees.c
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

// Search function
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else
    {
        return true;
    }
}
```

### Tree Operations
- Insertion
- Deletion
- Traversal (Pre-order, In-order, Post-order)
- Search

## Queues

### Queue Implementation
```c
// From quee.c
typedef struct node
{
    int number;
    struct node *next;
}
node;

node *head = NULL;
node *tail = NULL;

// Enqueue function
void enqueue(int number)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }
    n->number = number;
    n->next = NULL;
    
    if (tail != NULL)
    {
        tail->next = n;
    }
    tail = n;
    
    if (head == NULL)
    {
        head = n;
    }
}

// Dequeue function
int dequeue(void)
{
    if (head == NULL)
    {
        return -1;
    }
    
    int number = head->number;
    node *tmp = head->next;
    free(head);
    head = tmp;
    
    if (head == NULL)
    {
        tail = NULL;
    }
    
    return number;
}
```

## Implementation Examples

### Sorted Linked List
```c
// From sorted_list.c
void insert_sorted(int number)
{
    // Create new node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }
    n->number = number;
    n->next = NULL;

    // Special case for empty list
    if (list == NULL)
    {
        list = n;
        return;
    }

    // Special case for insertion at beginning
    if (number < list->number)
    {
        n->next = list;
        list = n;
        return;
    }

    // Find insertion point
    node *current = list;
    while (current->next != NULL && current->next->number < number)
    {
        current = current->next;
    }

    // Insert node
    n->next = current->next;
    current->next = n;
}
```

## Practice Problems

1. Implement a doubly linked list
2. Create a hash table with chaining
3. Build a binary search tree with deletion
4. Implement a priority queue

## Common Pitfalls to Avoid

1. Memory leaks in linked data structures
2. Not handling NULL pointers
3. Incorrect pointer manipulation
4. Poor hash function design
5. Not maintaining data structure invariants

## Additional Resources

- [CS50 Data Structures Notes](https://cs50.harvard.edu/x/2024/notes/5/)
- [Visualizing Data Structures](https://visualgo.net/)
- [Big O Cheat Sheet for Data Structures](https://www.bigocheatsheet.com/) 