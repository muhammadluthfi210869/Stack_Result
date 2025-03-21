#ifndef STACK_H
#define STACK_H

#include "ElmtList.h"

// Tipe data stack menggunakan linked list
typedef struct {
    address TOP;  // Pointer to top element
} Stack;

// Operasi-operasi dasar stack
void initStack(Stack *S);           // Inisialisasi stack
void push(Stack *S, int value);     // Push element to stack
int pop(Stack *S);                  // Pop and return top element
int peek(Stack S);                  // View top element without removing
int isStackEmpty(Stack S);          // Check if stack is empty
void printStack(Stack S);           // Print all elements in stack
void clearStack(Stack *S);          // Clear all elements from stack

#endif 