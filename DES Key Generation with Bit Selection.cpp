#include <stdio.h>
#include <string.h>

void generate_des_keys(char *key) {
    unsigned char subkeys[16][6];

    for (int i = 0; i < 16; i++) {
        
        memcpy(subkeys[i], &key[i % 8], 6);
    }

    printf("Generated subkeys:\n");
    for (int i = 0; i < 16; i++) {
        printf("K%d: ", i + 1);
        for (int j = 0; j < 6; j++)
            printf("%02X ", subkeys[i][j]);
        printf("\n");
    }
}

int main() {
    char key[8] = "KEYVALUE";  
    generate_des_keys(key);
    return 0;
}
