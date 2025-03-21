#include "ElmtList.h"

// Membuat elemen baru
address createElmtList(int info) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        P->info = info;
        P->next = Nil;
    }
    return P;
}

// Menyisipkan elemen di awal list
void insertAtFirst(address *First, int x) {
    address new = (address)malloc(sizeof(ElmtList));
    new->info = x;
    new->next = *First;
    *First = new;
}

// Menyisipkan elemen di akhir list
void insertAtLast(address *First, int x) {
    if (*First == Nil) {
        insertAtFirst(First, x);
    } else {
        address temp = *First;
        while (temp->next != Nil) {
            temp = temp->next;
        }
        address new = (address)malloc(sizeof(ElmtList));
        new->info = x;
        new->next = Nil;
        temp->next = new;
    }
}

// Menyisipkan elemen setelah elemen tertentu
void insertAfter(address *First, int x, int prev) {
    address temp = *First;
    while (temp != Nil && temp->info != prev) {
        temp = temp->next;
    }
    if (temp != Nil) {
        address new = (address)malloc(sizeof(ElmtList));
        new->info = x;
        new->next = temp->next;
        temp->next = new;
    }
}

// Menghapus elemen pertama
void deleteFirst(address *First) {
    if (*First != Nil) {
        address temp = *First;
        *First = temp->next;
        free(temp);
    }
}

// Menghapus elemen terakhir
void deleteLast(address *First) {
    if (*First != Nil) {
        if ((*First)->next == Nil) {
            free(*First);
            *First = Nil;
        } else {
            address temp = *First;
            while (temp->next->next != Nil) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = Nil;
        }
    }
}

// Menghapus elemen dengan info tertentu
void deleteByInfo(address *First, int x) {
    if (*First != Nil) {
        if ((*First)->info == x) {
            deleteFirst(First);
        } else {
            address temp = *First;
            while (temp->next != Nil && temp->next->info != x) {
                temp = temp->next;
            }
            if (temp->next != Nil) {
                address del = temp->next;
                temp->next = del->next;
                free(del);
            }
        }
    }
}

// Menghapus semua elemen
void deleteAll(address *First) {
    while (*First != Nil) {
        deleteFirst(First);
    }
}

// Mencetak list
void printList(address First) {
    address temp = First;
    while (temp != Nil) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}