#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define ALPHABET_SIZE 26

void generateCipher(const char *keyword, char cipherMap[]) {
    int used[26] = {0};
    int index = 0;

    // Fill cipher with keyword letters first
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);  // Convert to uppercase
        if (!used[ch - 'A']) {
            cipherMap[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Fill remaining letters in alphabetical order
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipherMap[index++] = ch;
        }
    }
}

void encryptText(const char *plaintext, char *ciphertext, char cipherMap[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);  // Convert to uppercase
        if (isalpha(ch)) {
            ciphertext[i] = cipherMap[ch - 'A'];  // Replace with mapped letter
        } else {
            ciphertext[i] = plaintext[i];  // Keep spaces/punctuation
        }
    }
    ciphertext[strlen(plaintext)] = '\0';  // Null-terminate
}

void decryptText(const char *ciphertext, char *plaintext, char cipherMap[]) {
    char alphabet[ALPHABET_SIZE + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = toupper(ciphertext[i]);  // Convert to uppercase
        if (isalpha(ch)) {
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (cipherMap[j] == ch) {
                    plaintext[i] = alphabet[j];  // Find original letter
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i];  // Keep spaces/punctuation
        }
    }
    plaintext[strlen(ciphertext)] = '\0';  // Null-terminate
}

int main() {
    char keyword[] = "CIPHER";  // ? Fixed string initialization
    char cipherMap[ALPHABET_SIZE];

    generateCipher(keyword, cipherMap);

    printf("Cipher Mapping: ");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c ", cipherMap[i]);
    }
    printf("\n");

    char plaintext[] = "HELLO WORLD";
    char encrypted[100], decrypted[100];

    encryptText(plaintext, encrypted, cipherMap);
    printf("Encrypted: %s\n", encrypted);

    decryptText(encrypted, decrypted, cipherMap);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
