#include <stdio.h>

int main() {
    int x;  // Uninitialized variable
    printf("%d\n", x);  // Prints a garbage value
    
    return 0;
}