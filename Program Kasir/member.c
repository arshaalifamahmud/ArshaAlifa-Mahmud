#include <stdio.h>
#include <stdlib.h>
#include "member.h"

void tambahMember() {
    FILE *file = fopen("member.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int id;
    char nama[50];

    printf("Masukkan ID Member: ");
    scanf("%d", &id);
    printf("Masukkan Nama Member: ");
    scanf(" %[^\n]", nama);

    fprintf(file, "%d|%s|0\n", id, nama);  // Poin awal adalah 0
    fclose(file);
    printf("Member berhasil ditambahkan!\n");
}

void tambahPoinMember() {
    FILE *file = fopen("member.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int idCari, id, poin, poinTambah;
    char nama[50];

    printf("Masukkan ID Member: ");
    scanf("%d", &idCari);
    printf("Masukkan Poin yang akan ditambahkan: ");
    scanf("%d", &poinTambah);

    while (fscanf(file, "%d|%[^|]|%d\n", &id, nama, &poin) != EOF) {
        if (id == idCari) {
            poin += poinTambah;
            printf("Poin berhasil ditambahkan. Total Poin: %d\n", poin);
        }
        fprintf(temp, "%d|%s|%d\n", id, nama, poin);
    }

    fclose(file);
    fclose(temp);

    remove("member.txt");
    rename("temp.txt", "member.txt");
}