#include <stdio.h>
#include <ctype.h>

void caesarCipher(char *text, int shift) {
    char c;
    while (*text) {
        c = *text;
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (c - offset + shift) % 26 + offset;
        }
        putchar(c);
        text++;
    }
}

int main() {
    char text[] = "HELLO WORLD";
    int shift = 3;  
    printf("Original: %s\n", text);
    printf("Encrypted: ");
    caesarCipher(text, shift);
    printf("\n");
    return 0;
}
