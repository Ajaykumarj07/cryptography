#include <stdio.h>
#include <string.h>

#define ALPHA 26


char freq_order[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";


void count_frequencies(char *text, int freq[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') freq[text[i] - 'A']++;
    }
}


int find_shift(int freq[]) {
    int max_index = 0;
    for (int i = 1; i < ALPHA; i++) {
        if (freq[i] > freq[max_index]) max_index = i;
    }
    return (max_index - ('E' - 'A') + ALPHA) % ALPHA;
}


void decrypt(char *ciphertext, int shift) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = ((ciphertext[i] - 'A' - shift + ALPHA) % ALPHA) + 'A';
        }
    }
}

int main() {
    char ciphertext[] = "LCLLE JWPDU OLCLY"; 
    int freq[ALPHA] = {0};

    count_frequencies(ciphertext, freq);
    int shift = find_shift(freq);

    decrypt(ciphertext, shift);
    printf("Possible plaintext: %s\n", ciphertext);

    return 0;
}
