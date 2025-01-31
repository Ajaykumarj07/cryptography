#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char keySquare[SIZE][SIZE];  


void generateKeySquare(char *key) {
    int used[26] = {0};  
    int i, j, index = 0;
    

    for (i = 0; key[i] != '\0'; i++) {
        if (key[i] == 'J') key[i] = 'I';  
        if (!used[toupper(key[i]) - 'A']) {
            keySquare[index / SIZE][index % SIZE] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            index++;
        }
    }
    
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; 
        if (!used[c - 'A']) {
            keySquare[index / SIZE][index % SIZE] = c;
            used[c - 'A'] = 1;
            index++;
        }
    }
}

void formatPlaintext(char *text, char *formatted) {
    int len = strlen(text), j = 0;
    
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            formatted[j++] = toupper(text[i] == 'J' ? 'I' : text[i]);
        }
    }
    formatted[j] = '\0';

    if (j % 2 != 0) {
        formatted[j++] = 'X';
        formatted[j] = '\0';
    }
}

void findPosition(char letter, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keySquare[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void playfairEncrypt(char *text) {
    char formatted[100];
    formatPlaintext(text, formatted);

    printf("Encrypted: ");
    for (int i = 0; i < strlen(formatted); i += 2) {
        int row1, col1, row2, col2;
        findPosition(formatted[i], &row1, &col1);
        findPosition(formatted[i + 1], &row2, &col2);

        if (row1 == row2) {
            printf("%c%c", keySquare[row1][(col1 + 1) % SIZE], keySquare[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2) { 
            printf("%c%c", keySquare[(row1 + 1) % SIZE][col1], keySquare[(row2 + 1) % SIZE][col2]);
        } else {  
            printf("%c%c", keySquare[row1][col2], keySquare[row2][col1]);
        }
    }
    printf("\n");
}


void playfairDecrypt(char *text) {
    printf("Decrypted: ");
    for (int i = 0; i < strlen(text); i += 2) {
        int row1, col1, row2, col2;
        findPosition(text[i], &row1, &col1);
        findPosition(text[i + 1], &row2, &col2);

        if (row1 == row2) {  
            printf("%c%c", keySquare[row1][(col1 - 1 + SIZE) % SIZE], keySquare[row2][(col2 - 1 + SIZE) % SIZE]);
        } else if (col1 == col2) {  
            printf("%c%c", keySquare[(row1 - 1 + SIZE) % SIZE][col1], keySquare[(row2 - 1 + SIZE) % SIZE][col2]);
        } else {  
            printf("%c%c", keySquare[row1][col2], keySquare[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char keyword[] = "KEYWORD"; 
    char plaintext[] = "MUST SEE YOU OVER CADOGAN WEST";
    
    generateKeySquare(keyword);

    printf("Playfair Key Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", keySquare[i][j]);
        }
        printf("\n");
    }

    printf("Original: %s\n", plaintext);
    playfairEncrypt(plaintext);

    char ciphertext[] = "XOVKZ ETTZ CWNZ RSGV ZJHL"; 
    playfairDecrypt(ciphertext);

    return 0;
}
