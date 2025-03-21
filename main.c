#include "queue.h"

int main() {
    TellerQueue tellers[MAX_TELLERS];
    initTellerQueues(tellers, MAX_TELLERS);
    
    int choice;
    do {
        printf("\nSistem Antrian Bank\n");
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Proses Nasabah\n");
        printf("3. Tampilkan Semua Antrian\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCustomer(tellers, MAX_TELLERS);
                printQueues(tellers, MAX_TELLERS);
                break;
            case 2:
                processCustomer(tellers, MAX_TELLERS);
                printQueues(tellers, MAX_TELLERS);
                break;
            case 3:
                printQueues(tellers, MAX_TELLERS);
                break;
            case 4:
                printf("Terima kasih telah menggunakan layanan kami!\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (choice != 4);
    
    // Membersihkan semua antrian
    for (int i = 0; i < MAX_TELLERS; i++) {
        deleteAll(&tellers[i].queue);
    }
    
    return 0;
} 