#include <stdio.h>

int globalVar = 10;  // Global scope

void exampleFunction() {
    int localVar = 20;  // Local scope
    printf("Local: %d, Global: %d\n", localVar, globalVar);
    
    {
        int blockVar = 30;  // Block scope
        printf("Block: %d\n", blockVar);
    }
    // blockVar is not accessible here
}

int main() {
    exampleFunction();
    // localVar is not accessible here
    printf("Global: %d\n", globalVar);
    return 0;
}