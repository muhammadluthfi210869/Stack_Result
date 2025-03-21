#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Inisialisasi stack
void initStack(Stack *S) {
    S->TOP = Nil;
}

// Push: menambahkan elemen ke puncak stack
void push(Stack *S, int value) {
    insertAtFirst(&(S->TOP), value);
}

// Pop: mengambil dan menghapus elemen puncak stack
int pop(Stack *S) {
    if (S->TOP == Nil) {
        printf("Error: Stack kosong\n");
        return -1;
    }
    int value = S->TOP->info;
    deleteFirst(&(S->TOP));
    return value;
}

// Peek: melihat elemen puncak stack tanpa menghapusnya
int peek(Stack S) {
    if (S.TOP == Nil) {
        printf("Error: Stack kosong\n");
        return -1;
    }
    return S.TOP->info;
}

// IsEmpty: mengecek apakah stack kosong
int isStackEmpty(Stack S) {
    return (S.TOP == Nil);
}

// PrintStack: mencetak isi stack
void printStack(Stack S) {
    address P = S.TOP;
    printf("Isi stack: ");
    while (P != Nil) {
        printf("%d ", P->info);
        P = P->next;
    }
    printf("\n");
}

// ClearStack: membersihkan seluruh elemen stack
void clearStack(Stack *S) {
    deleteAll(&(S->TOP));
    S->TOP = Nil;
} 