#include <stdio.h>

void modifyValue(int x) {
    x = x * 2;  // This modifies the local copy, not the original
    printf("Inside function: %d\n", x);
}

int main() {
    int num = 5;
    printf("Before function call: %d\n", num);
    
    modifyValue(num);
    
    printf("After function call: %d\n", num);  // num remains unchanged
    
    return 0;
}