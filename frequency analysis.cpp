#include <stdio.h>
#include <ctype.h>

void frequencyAnalysis(char *text) {
    int freq[26] = {0};

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            freq[toupper(text[i]) - 'A']++;
        }
    }

    printf("Letter Frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, freq[i]);
    }
}

int main() {
    char ciphertext[] = "GUVF VF ZL FRPERG ZRFFNTR";
    frequencyAnalysis(ciphertext);
    return 0;
}
