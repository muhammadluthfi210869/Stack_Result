#ifndef QUEUE_H
#define QUEUE_H

#include "ElmtList.h"

#define MAX_TELLERS 3

// Struktur untuk merepresentasikan antrian teller
typedef struct {
    char teller_id;
    address queue;
    int count;
    int last_processed;
} TellerQueue;

// Fungsi-fungsi untuk mengelola antrian
void initTellerQueues(TellerQueue tellers[], int n);
TellerQueue* findShortestQueue(TellerQueue tellers[], int n);
TellerQueue* findNextTellerToProcess(TellerQueue tellers[], int n);
void addCustomer(TellerQueue tellers[], int n);
void processCustomer(TellerQueue tellers[], int n);
void printQueues(TellerQueue tellers[], int n);

#endif 