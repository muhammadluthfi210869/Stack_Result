#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"
#include "stack.h"

void decimalToBinary(int decimal) {
    Stack S;
    initStack(&S);
    
    // If decimal is 0, handle it specially
    if (decimal == 0) {
        printf("Bilangan biner: 0\n");
        return;
    }
    
    // Convert decimal to binary by repeatedly dividing by 2
    // and pushing remainders to stack
    while (decimal > 0) {
        push(&S, decimal % 2);
        decimal = decimal / 2;
    }
    
    // Print binary number by popping all elements from stack
    printf("Bilangan biner: ");
    while (!isStackEmpty(S)) {
        printf("%d", pop(&S));
    }
    printf("\n");
    
    // Make sure stack is clean
    clearStack(&S);
} 