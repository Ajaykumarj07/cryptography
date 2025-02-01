#include <stdio.h>
#include <openssl/des.h>

void DES_decrypt(char *ciphertext, char *key) {
    DES_cblock key_block;
    DES_key_schedule schedule;

    memcpy(key_block, key, 8);
    DES_set_key_unchecked(&key_block, &schedule);


    DES_key_schedule rev_schedule;
    for (int i = 0; i < 16; i++)
        rev_schedule.ks[i] = schedule.ks[15 - i];

    DES_cblock plaintext;
    DES_ecb_encrypt((DES_cblock *)ciphertext, &plaintext, &rev_schedule, DES_DECRYPT);
    
    printf("Decrypted text: %s\n", plaintext);
}

int main() {
    char ciphertext[8] = "EXAMPLE"; 
    char key[8] = "MYSECRET"; 

    DES_decrypt(ciphertext, key);

    return 0;
}
