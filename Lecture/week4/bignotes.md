### Pixels
- picture is a collection of pixels put togheter in a grid to form a picture
- each pixel can be 0 or 1 resprenting black or white
## Examples: smily face
1 1 0 0 0 0 1 1
1 0 1 1 1 1 0 1
0 1 0 1 1 0 1 0
0 1 1 1 1 1 1 0
0 1 0 1 1 0 1 0
0 1 1 0 0 1 1 0
1 0 1 1 1 1 0 1
1 1 0 0 0 0 1 1
### Pixels
- Pixels on a computer are represented using RGB color. The RGB color model consists of a 3D vector where (0,0,0) represents black and (255,255,255) represents white.
- In the RGB model, red is denoted by FF 00 00, green by 00 FF 00, and blue by 00 00 FF in software like Photoshop.
- The hex color codes #000000 and #FFFFFF are used to represent black and white respectively.
- Hex color codes use the characters 0-9 and A-F (or a-f) to represent colors in base-16, where 0 is the smallest value and FF is the largest.
- Examples of hex color codes include #FF0000 for red, #00FF00 for green, #0000FF for blue, #FF00FF for magenta, #00FFFF for cyan, #FFFFFF for white, and #000000 for black.

- to distinct we add 0 before the hex code like 0X0 or 0x1 or 0x2 osv osv osv
# Pointers
## Pointers in C
- A pointer is a variable that stores the memory address of another variable.
- To store the memory address of a variable, we use the "&" operator, and to access the value stored at that memory address, we use the "*" operator.
- In the same function, we can check the memory address by using `(void*)&number`.

## Pointer Arithmetic
- Pointer arithmetic in C allows you to perform arithmetic operations on pointers.
- For example, if `ptr` is a pointer pointing to an integer, `ptr++` will increment the pointer to point to the next memory location of the same data type.
-  arithmetic is a powerful feature in C that can be used to iterate over arrays efficiently.
```cPointer
#include <stdio.h>

int main(void)
{
    int number = 5;
    printf("The address of the variable 'number' is: %p\n", (void*)&number);
    return 0;
}
```
### a exempel i found for pointers
```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr; // ptr points to the first element of arr
for (int i = 0; i < 5; i++) {
    printf("%d ", *ptr); // Print the value pointed by ptr
    ptr++; // Move ptr to the next element
}
```
