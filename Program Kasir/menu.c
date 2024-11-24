#include <stdio.h>
#include "barang.h"
#include "member.h"
#include "penjualan.h"
#include "menu.h"

void menu() {
    int pilihan;

    do {
        printf("\n===== Sistem Kasir =====\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Daftar Barang\n");
        printf("3. Hapus Barang\n");
        printf("4. Pembayaran\n");
        printf("5. Tambah Member\n");
        printf("6. Tambah Poin Member\n");
        printf("7. Laporan Penjualan\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                lihatDaftarBarang();
                break;
            case 3:
                hapusBarang();
                break;
            case 4:
                pembayaran();
                break;
            case 5:
                tambahMember();
                break;
            case 6:
                tambahPoinMember();
                break;
            case 7:
                laporanPenjualan();
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}

