#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pembayaran.h"

void pembayaran() {
    FILE *fileBarang = fopen("barang.txt", "r");
    FILE *filePenjualan = fopen("penjualan.txt", "a");
    FILE *temp = fopen("temp.txt", "w");

    if (fileBarang == NULL || filePenjualan == NULL || temp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int idCari, jumlah, id, stok, harga, found = 0;
    char nama[50], kategori[50];

    printf("Masukkan ID Barang: ");
    scanf("%d", &idCari);
    printf("Masukkan Jumlah Barang: ");
    scanf("%d", &jumlah);

    while (fscanf(fileBarang, "%d|%[^|]|%[^|]|%d|%d\n", &id, nama, kategori, &harga, &stok) != EOF) {
        if (id == idCari) {
            found = 1;
            if (stok >= jumlah) {
                stok -= jumlah;
                fprintf(filePenjualan, "%d|%d|%d\n", id, jumlah, harga * jumlah);
                printf("Pembayaran berhasil! Total: %d\n", harga * jumlah);
            } else {
                printf("Stok tidak mencukupi.\n");
            }
        }
        fprintf(temp, "%d|%s|%s|%d|%d\n", id, nama, kategori, harga, stok);
    }

    if (!found) {
        printf("Barang tidak ditemukan.\n");
    }

    fclose(fileBarang);
    fclose(filePenjualan);
    fclose(temp);

    remove("barang.txt");
    rename("temp.txt", "barang.txt");
}
