#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showHeader() {
    printf("=============================================\n");
    printf("     KONVERSI DESIMAL KE BINER (STACK)     \n");
    printf("=============================================\n");
}

int main() {
    int decimal;
    char lanjut;
    
    do {
        clearScreen();
        showHeader();
        
        printf("\nMasukkan bilangan desimal: ");
        if (scanf("%d", &decimal) != 1) {
            printf("Error: Input harus berupa bilangan!\n");
            while (getchar() != '\n'); // Clear input buffer
        } else if (decimal < 0) {
            printf("Error: Bilangan harus non-negatif!\n");
        } else {
            decimalToBinary(decimal);
        }
        
        printf("\nIngin mengkonversi bilangan lain? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        scanf("%c", &lanjut);
        
    } while (lanjut == 'y' || lanjut == 'Y');
    
    printf("\nTerima kasih telah menggunakan program ini!\n");
    return 0;
} 