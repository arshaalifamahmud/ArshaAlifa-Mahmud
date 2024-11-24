#include <stdio.h>
#include <string.h>

// Fungsi login
int login() {
    char username[50], password[50];
    char correctUsername[] = "admin";
    char correctPassword[] = "12345";

    printf("===== Login =====\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        printf("Login berhasil!\n");
        return 1;
    } else {
        printf("Username atau password salah.\n");
        return 0;
    }
}

