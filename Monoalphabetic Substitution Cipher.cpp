#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipher_map[26] = {
    'M', 'F', 'H', 'I', 'K',
    'U', 'N', 'O', 'P', 'Q',
    'Z', 'V', 'W', 'X', 'Y',
    'E', 'L', 'A', 'R', 'G',
    'D', 'S', 'T', 'B', 'C'
};

void encryptMono(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char upper = toupper(text[i]);
            int index = (upper == 'J') ? ('I' - 'A') : (upper - 'A'); 
            putchar(cipher_map[index]);
        } else {
            putchar(text[i]);
        }
    }
    printf("\n");
}

int main() {
    char message[] = "HELLO WORLD";
    printf("Encrypted: ");
    encryptMono(message);
    return 0;
}
