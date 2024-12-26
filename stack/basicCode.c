#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    char *arr;
    int size;
};

int main() {
    // Create a stack pointer and allocate memory for the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    
    // Initialize the stack
    sp->size = 5;                    // Set stack size
    sp->top = -1;                    // Initialize top as empty
    sp->arr = (char *)malloc(sp->size * sizeof(char)); // Allocate array for stack
    
    // Simulate pushing an element
    sp->top++;
    sp->arr[sp->top] = 'A';          // Push 'A' onto the stack
    
    printf("Top element: %c\n", sp->arr[sp->top]); // Output the top element

    // Free allocated memory
    free(sp->arr);
    free(sp);

    return 0;
}
