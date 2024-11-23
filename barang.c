#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi-fungsi
void tambahBarang();
void lihatDaftarBarang();
void hapusBarang();
void pembayaran();
void tambahMember();
void tambahPoinMember();
void laporanPenjualan();
void menu();

// Fungsi untuk menambahkan barang
void tambahBarang() {
    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int id, stok, harga;
    char nama[50], kategori[50];

    printf("Masukkan ID Barang: ");
    scanf("%d", &id);
    printf("Masukkan Nama Barang: ");
    scanf(" %[^\n]", nama);
    printf("Masukkan Kategori Barang: ");
    scanf(" %[^\n]", kategori);
    printf("Masukkan Harga Barang: ");
    scanf("%d", &harga);
    printf("Masukkan Stok Barang: ");
    scanf("%d", &stok);

    fprintf(file, "%d|%s|%s|%d|%d\n", id, nama, kategori, harga, stok);
    fclose(file);
    printf("Barang berhasil ditambahkan!\n");
}

// Fungsi untuk melihat daftar barang
void lihatDaftarBarang() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Data barang belum ada.\n");
        return;
    }

    char buffer[255];
    printf("ID | Nama Barang | Kategori | Harga | Stok\n");
    printf("-------------------------------------------\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

// Fungsi untuk menghapus barang
void hapusBarang() {
    FILE *file = fopen("barang.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int idHapus, id;
    char nama[50], kategori[50];
    int harga, stok;

    printf("Masukkan ID Barang yang ingin dihapus: ");
    scanf("%d", &idHapus);

    while (fscanf(file, "%d|%[^|]|%[^|]|%d|%d\n", &id, nama, kategori, &harga, &stok) != EOF) {
        if (id != idHapus) {
            fprintf(temp, "%d|%s|%s|%d|%d\n", id, nama, kategori, harga, stok);
        }
    }

    fclose(file);
    fclose(temp);

    remove("barang.txt");
    rename("temp.txt", "barang.txt");

    printf("Barang berhasil dihapus.\n");
}
