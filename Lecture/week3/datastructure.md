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
