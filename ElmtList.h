#ifndef ELMTLIST_H
#define ELMTLIST_H

#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
typedef struct TElmtList *address;
typedef struct TElmtList {
    int info;
    address next;
} ElmtList;

void insertAtFirst(address *First, int x);
void insertAtLast(address *First, int x);
void insertAfter(address *First, int x, int prev);
void deleteFirst(address *First);
void deleteLast(address *First);
void deleteByInfo(address *First, int x);
void deleteAll(address *First);
void printList(address First);

#endif