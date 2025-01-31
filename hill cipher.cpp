#include <stdio.h>

#define SIZE 2 

void multiplyMatrices(int key[SIZE][SIZE], int text[SIZE], int result[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            result[i] += key[i][j] * text[j];
        }
        result[i] %= 26;
    }
}

void hillCipherEncrypt(char *message, int key[SIZE][SIZE]) {
    int text[SIZE], encrypted[SIZE];

    for (int i = 0; message[i] != '\0'; i += 2) {
        text[0] = message[i] - 'A';
        text[1] = message[i + 1] - 'A';

        multiplyMatrices(key, text, encrypted);
        printf("%c%c", encrypted[0] + 'A', encrypted[1] + 'A');
    }
    printf("\n");
}

int main() {
    char message[] = "MEETMEATTHEUSUALPLACE";
    int key[SIZE][SIZE] = {
        {9, 4},
        {5, 7}
    };

    printf("Encrypted: ");
    hillCipherEncrypt(message, key);
    return 0;
}
