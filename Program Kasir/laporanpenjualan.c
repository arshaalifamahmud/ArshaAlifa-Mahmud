#include <stdio.h>
#include "laporanPenjualan.h"

// Implementasi fungsi laporanPenjualan
void laporanPenjualan() {
    FILE *file = fopen("penjualan.txt", "r");
    if (file == NULL) {
        printf("Belum ada data penjualan.\n");
        return;
    }

    char buffer[255];

    printf("ID Barang | Jumlah | Total Harga\n");
    printf("-------------------------------\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

