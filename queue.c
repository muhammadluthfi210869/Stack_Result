#include "queue.h"

// Inisialisasi antrian teller
void initTellerQueues(TellerQueue tellers[], int n) {
    for (int i = 0; i < n; i++) {
        tellers[i].teller_id = 'A' + i;
        tellers[i].queue = Nil;
        tellers[i].count = 0;
        tellers[i].last_processed = 0;
    }
}

// Mencari teller dengan antrian terpendek
TellerQueue* findShortestQueue(TellerQueue tellers[], int n) {
    TellerQueue* shortest = &tellers[0];
    for (int i = 1; i < n; i++) {
        if (tellers[i].count < shortest->count) {
            shortest = &tellers[i];
        }
    }
    return shortest;
}

// Mencari teller berikutnya yang harus diproses
TellerQueue* findNextTellerToProcess(TellerQueue tellers[], int n) {
    TellerQueue* next = NULL;
    int min_number = 999999; // Nilai awal yang besar
    
    for (int i = 0; i < n; i++) {
        if (tellers[i].queue != Nil) {
            // Cek apakah nomor antrian ini adalah yang terkecil
            if (tellers[i].queue->info < min_number) {
                min_number = tellers[i].queue->info;
                next = &tellers[i];
            }
        }
    }
    return next;
}

// Menambahkan nasabah ke antrian
void addCustomer(TellerQueue tellers[], int n) {
    TellerQueue* teller = findShortestQueue(tellers, n);
    int queueNumber = (teller->count + 1);
    insertAtLast(&teller->queue, queueNumber);
    teller->count++;
    printf("Nasabah ditambahkan ke Teller %c dengan nomor %c%d\n", 
           teller->teller_id, teller->teller_id, queueNumber);
}

// Memproses nasabah dari antrian
void processCustomer(TellerQueue tellers[], int n) {
    TellerQueue* teller = findNextTellerToProcess(tellers, n);
    
    if (teller != NULL) {
        printf("Memproses nasabah %c%d dari Teller %c\n", 
               teller->teller_id, teller->queue->info, teller->teller_id);
        deleteFirst(&teller->queue);
        teller->count--;
        teller->last_processed = teller->queue ? teller->queue->info : 0;
    } else {
        printf("Tidak ada nasabah dalam antrian!\n");
    }
}

// Mencetak semua antrian
void printQueues(TellerQueue tellers[], int n) {
    printf("\n==========================================\n");
    printf("           STATUS ANTRIAN BANK            \n");
    printf("==========================================\n");
    
    // Mencari panjang antrian terpanjang
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        if (tellers[i].count > max_length) {
            max_length = tellers[i].count;
        }
    }
    
    // Mencetak header teller
    printf("\nTeller\t");
    for (int i = 0; i < n; i++) {
        printf("Teller %c\t", tellers[i].teller_id);
    }
    printf("\n");
    
    // Mencetak garis pemisah
    printf("----------------------------------------\n");
    
    // Mencetak antrian per baris
    for (int row = 0; row < max_length; row++) {
        printf("Antrian %d\t", row + 1);
        for (int i = 0; i < n; i++) {
            address current = tellers[i].queue;
            int pos = 0;
            while (current != Nil && pos < row) {
                current = current->next;
                pos++;
            }
            if (current != Nil) {
                printf("%c%d\t", tellers[i].teller_id, current->info);
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }
    
    // Mencetak jumlah antrian per teller
    printf("----------------------------------------\n");
    printf("Total\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", tellers[i].count);
    }
    printf("\n");
    printf("==========================================\n\n");
} 